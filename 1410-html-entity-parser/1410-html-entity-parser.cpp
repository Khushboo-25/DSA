class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> mp = {
            {"&quot;", '"'},
            {"&apos;", '\''},
            {"&amp;", '&'},
            {"&gt;", '>'},
            {"&lt;", '<'},
            {"&frasl;", '/'}
        };

        string ans = "";
        int n = text.size();

        for (int i = 0; i < n; i++) {
            if (text[i] == '&') {
                bool found = false;
                for (auto &it : mp) {
                    string key = it.first;
                    int len = key.size();
                    if (i + len <= n && text.substr(i, len) == key) {
                        ans.push_back(it.second);
                        i += len - 1;
                        found = true;
                        break;
                    }
                }
                if (!found) ans.push_back(text[i]);
            } else {
                ans.push_back(text[i]);
            }
        }
        return ans;
    }
};
