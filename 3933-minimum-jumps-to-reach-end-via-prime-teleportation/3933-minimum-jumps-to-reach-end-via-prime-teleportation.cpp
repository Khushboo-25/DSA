class Solution {
    vector<bool> getPrimeSieve(int maxVal) {
        vector<bool> prime(maxVal + 1, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= maxVal; ++p) {
            if (prime[p]) {
                for (int i = p * p; i <= maxVal; i += p) {
                    prime[i] = false;
                }
            }
        }
        return prime;
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        vector<int> mordelvian = nums;

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime = getPrimeSieve(maxVal);
        // primes mark

        unordered_map<int, vector<int>> teleportMap;

        for (int i = 0; i < n; ++i) {
            for (int p = 2; p * p <= nums[i]; ++p) {
                if (nums[i] % p == 0 && isPrime[p]) {
                    teleportMap[p].push_back(i);
                    while (nums[i] % p == 0) nums[i] /= p;
                }
            }
            if (nums[i] > 1 && isPrime[nums[i]]) {
                teleportMap[nums[i]].push_back(i);
            }
        }

        // BFS
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;

        unordered_set<int> usedPrimes; 

        while (!q.empty()) {
            auto [i, dist] = q.front();
            q.pop();

            if (i == n - 1) return dist;

            // Adjacent moves
            if (i - 1 >= 0 && !visited[i - 1]) {
                visited[i - 1] = true;
                q.push({i - 1, dist + 1});
            }
            if (i + 1 < n && !visited[i + 1]) {
                visited[i + 1] = true;
                q.push({i + 1, dist + 1});
            }

            int val = mordelvian[i];
            if (isPrime[val] && usedPrimes.find(val) == usedPrimes.end()) {
                for (int j : teleportMap[val]) {
                    if (j != i && !visited[j]) {
                        visited[j] = true;
                        q.push({j, dist + 1});
                    }
                }
                usedPrimes.insert(val);
            }
        }

        return -1; 
    }
};