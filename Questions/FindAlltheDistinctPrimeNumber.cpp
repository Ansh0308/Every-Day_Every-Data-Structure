#include <bits/stdc++.h>
using namespace std;

// Sieve primes up to n (inclusive)
// vector<int> countPrimes(int n) {
//     if(n < 2) return {};
//     vector<bool> isPrime(n + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     for(int i=2; i*i <= n; i++) {
//         if(isPrime[i]){
//             for(int j=i*i; j <= n; j+=i) {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     vector<int> ans;
//     for(int i=2; i<=n; i++) {
//         if(isPrime[i]) ans.push_back(i);
//     }
//     return ans;
// }

// int solution(vector<vector<int>> &arg){
//     int maxRange = INT_MIN;
//     for(auto &row : arg)
//         maxRange = max(maxRange, row[1]);

//     vector<int> allPrime = countPrimes(maxRange); // sieve up to maxRange
//     set<int> UniquePrime;

//     for(auto &row : arg) {
//         int l = row[0], r = row[1]; // Assuming ranges are inclusive
//         for(int p : allPrime) {
//             if(p >= l && p <= r) {
//                 UniquePrime.insert(p);
//             }
//         }
//     }
//     return UniquePrime.size();
// }
#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

// Sieve and prefix count of primes
vector<int> PrefixcountPrimes(int n) {
    vector<int> ans(n + 1, 0);
    if (n < 2) return ans;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + (isPrime[i] ? 1 : 0);
    }
    return ans;
}

// Calculates count of distinct primes in the provided ranges
int DistinctPrimesInRanges(const vector<vector<int>>& ranges) {
    int maxRange = INT_MIN;
    for (const auto& row : ranges)
        maxRange = max(maxRange, row[1]);

    vector<int> prefixPrimes = PrefixcountPrimes(maxRange);
    set<int> uniquePrimes;

    for (int p = 2; p <= maxRange; p++) {
        if (prefixPrimes[p] > prefixPrimes[p - 1]) {  // p is prime
            for (const auto& row : ranges) {
                if (p >= row[0] && p <= row[1]) {
                    uniquePrimes.insert(p);
                    break;
                }
            }
        }
    }
    return uniquePrimes.size();
}

// New function: reads number of ranges and range bounds, returns distinct primes count
int ReadRangesAndReturnDistinctPrimes() {
    int rangeCount;
    
    cin >> rangeCount;
    vector<vector<int>> ranges(rangeCount, vector<int>(2));
    
    for (int i = 0; i < rangeCount; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
    }
    return DistinctPrimesInRanges(ranges);
}

int main() {
    int result = ReadRangesAndReturnDistinctPrimes();
    cout << "Total DISTINCT prime numbers in all ranges: " << result << endl;
    return 0;
}
