class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int N = 1000000;

        vector<int> isPrime(N+1, 1);
        isPrime[0] = isPrime[1] = 0;

        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = 0;
                }
            }
        }

        // store primes
        vector<int> primes;
        for (int i = 2; i <= N; i++) {
            if (isPrime[i]) primes.push_back(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // want prime
                if (isPrime[nums[i]]) continue;

                auto it = lower_bound(primes.begin(), primes.end(), nums[i]);
                if (it != primes.end()) {
                    ans += (*it - nums[i]);
                }
            } else {
                // want non-prime
                if (isPrime[nums[i]]) {
                    if (nums[i] == 2) ans += 2;
                    else ans += 1;
                }
            }
        }

        return ans;
    }
};