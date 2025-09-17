class Solution {
public:
bool check(string &s, int k) {
    if (k == 0) return true;
    vector<int> freq(256, 0);
    int unique = 0;

    for (int i = 0; i < s.size(); i++) {
        // add current char
        freq[s[i]]++;
        if (freq[s[i]] == 1) unique++;

        // maintain window size k
        if (i >= k) {
            freq[s[i - k]]--;
            if (freq[s[i - k]] == 0) unique--;
        }

        if (i >= k - 1 && unique == k) return true;
    }
    return false;
}


int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(s, mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}
    // int lengthOfLongestSubstring(string s) 
    // {
    //     unordered_map<int,int>pp;
    //     unordered_set<char>st;
    //     int ans=0;
    //     pp[0]=-1;
    //     int n=s.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         st.insert(s[i]);
    //         if(pp.find(st.size())!=pp.end())
    //         {
    //             ans=max(i-pp[st.size()],ans);
    //         }
    //         pp[st.size()]=i;
    //     }
    //     return ans;
        
    // }
};