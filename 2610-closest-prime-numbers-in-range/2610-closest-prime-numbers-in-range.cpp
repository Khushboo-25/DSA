#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = 1e6 + 1;
        vector<int> isPrime(n, 0);
        isPrime[0] = 1;
        isPrime[1] = 1;

        // Sieve of Eratosthenes
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i] == 0) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 1; // mark as not prime
                }
            }
        }

        int prevPrime = -1;
        int bestDiff = INT_MAX;
        vector<int> ans = {-1, -1};

        for (int i = left; i <= right; i++) {
            if (isPrime[i] == 0) { // prime found
                if (prevPrime != -1) {
                    int diff = i - prevPrime;
                    if (diff < bestDiff) {
                        bestDiff = diff;
                        ans = {prevPrime, i};
                    }
                }
                prevPrime = i;
            }
        }
        return ans;
    }
};
