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


int DistinctPrimesInRanges(vector<vector<int>> &ranges) {
    int maxRange = INT_MIN;
    for (auto &row : ranges)
        maxRange = max(maxRange, row[1]);

    vector<int> prefixPrimes = PrefixcountPrimes(maxRange);
    set<int> uniquePrimes;

    for (int p = 2; p <= maxRange; p++) {
        if (prefixPrimes[p] > prefixPrimes[p - 1]) {  // p is prime
            for (auto &row : ranges) {
                if (p >= row[0] && p <= row[1]) {
                    uniquePrimes.insert(p);
                    break;  // no need to check other ranges
                }
            }
        }
    }

    return uniquePrimes.size();
}


int main() {
    vector<vector<int>> ranges = {{1, 5}, {2, 6},{6,9}};
    int result = DistinctPrimesInRanges(ranges);
    cout << "Total DISTINCT prime numbers in all ranges: " << result << endl;
    return 0;
}
