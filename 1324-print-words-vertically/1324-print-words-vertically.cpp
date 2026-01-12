class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        string temp = "";
        
        // Split words
        for(char c : s) {
            if(c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        words.push_back(temp);
        
        // Find maximum word length
        int mx = 0;
        for(auto &w : words)
            mx = max(mx, (int)w.size());
        
        vector<string> ans;
        
        // Build vertical words
        for(int i = 0; i < mx; i++) {
            string cur = "";
            for(auto &w : words) {
                if(i < w.size())
                    cur += w[i];
                else
                    cur += ' ';
            }
            
            // Remove trailing spaces
            while(!cur.empty() && cur.back() == ' ')
                cur.pop_back();
            
            ans.push_back(cur);
        }
        
        return ans;
    }
};
