class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int ans = 0;
        
        // take all zeros (they don't affect numeric value)
        for(char c : s) if(c == '0') ans++;
        
        long long val = 0, pow2 = 1;
        int extraOnes = 0;
        
        // try taking 1s from the right side
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '1') {
                if(val + pow2 <= k) {
                    val += pow2;
                    extraOnes++;
                } else {
                    // can't include more left 1s
                    break;
                }
            }
            if(pow2 <= k) pow2 <<= 1;
            else break;
        }
        
        return ans + extraOnes;
    }
};
