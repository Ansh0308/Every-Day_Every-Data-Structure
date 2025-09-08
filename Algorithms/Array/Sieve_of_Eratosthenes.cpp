#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if (n < 2) return 0;
    int count = 0;
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
            for (int j = i * 2; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = countPrimes(n);
    cout << "Number of primes less than " << n << " is: " << result << endl;

    return 0;
}
