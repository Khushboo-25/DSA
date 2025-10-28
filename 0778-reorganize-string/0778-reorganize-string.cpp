class Solution {
public:
    string reorganizeString(string s) 
    {
    int n = s.size();
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    // Find max frequency and its character
    int fm = 0, ch = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > fm) {
            fm = freq[i];
            ch = i;
        }
    }

    // If impossible to rearrange
    if (fm > (n + 1) / 2) return "";

    string ans(n, ' ');
    int idx = 0;
     // Place max freq char at even indices
    while (freq[ch] > 0) {
        ans[idx] = (char)(ch + 'a');
        idx += 2;
        freq[ch]--;
    }

    // Fill remaining chars
    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            if (idx >= n) idx = 1; // move to odd indices
            ans[idx] = (char)(i + 'a');
            idx += 2;
            freq[i]--;
        }
    }

    return ans;
    }
};