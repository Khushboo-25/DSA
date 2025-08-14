class Solution {
public:
    int minimumPartition(string s, int k) {
        long long num = 0;
        int ans = 1; // start with first partition
        for (char c : s) {
            int digit = c - '0';
            if (digit > k) return -1; // impossible to form
            if (num * 10 + digit > k) {
                ans++;       // start new partition
                num = digit; // reset number
            } else {
                num = num * 10 + digit;
            }
        }
        return ans;
    }
};
