class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> ugly(n);  // Store the ugly numbers
        ugly[0] = 1;  // The first ugly number is 1

        int k = primes.size();
        vector<int> indices(k, 0);  // Store the current index for each prime
        vector<long long> next(k);  // Store the next multiple for each prime

        // Initialize the next multiples with the prime values
        for (int i = 0; i < k; ++i) {
            next[i] = primes[i];
        }

        for (int i = 1; i < n; ++i) {
            // Find the minimum value among the next multiples
            long long next_ugly = *min_element(next.begin(), next.end());
            ugly[i] = next_ugly;

            // Update the corresponding prime's multiple
            for (int j = 0; j < k; ++j) {
                if (next[j] == next_ugly) {
                    indices[j]++;
                    next[j] = ugly[indices[j]] * primes[j];
                }
            }
        }

        return ugly[n - 1];  // Return the nth ugly number
    }
};
