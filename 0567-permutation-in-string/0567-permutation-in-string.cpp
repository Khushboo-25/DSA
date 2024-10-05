class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        unordered_map<char, int> pp1, pp2;
        
        // Populate frequency map for s1
        for (char c : s1) {
            pp1[c]++;
        }
        
        int k = s1.size();
        int n = s2.size();
        
        // If s1 is longer than s2, s1 cannot be a substring of s2
        if (k > n) {
            return false;
        }
        
        // Populate initial frequency map for the first window of s2
        for (int i = 0; i < k; i++) {
            pp2[s2[i]]++;
        }
        if (pp1 == pp2) {
                return true;
            }
        // Now slide the window over s2
        for (int i = k; i <= n; i++) {
            // Check if the two maps are equal
            if (pp1 == pp2) {
                return true;
            }
            
            // Slide the window: remove the first character of the current window
            // and add the next character in the sequence
            if (i < n) {
                pp2[s2[i]]++;
                pp2[s2[i - k]]--;
                
                // If count goes to zero, remove the char from the map
                if (pp2[s2[i - k]] == 0) {
                    pp2.erase(s2[i - k]);
                }
            }
        }
        
        return false;
    }
};
