class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n=s.size();
        unordered_map<char,int>pp;
        for(auto it: s)
        pp[it]++;
        for(int i=0;i<n;i++)
        {
            if(pp[s[i]]<k)
            {
                int lf=longestSubstring(s.substr(0,i),k);
                int rf=longestSubstring(s.substr(i+1),k);
                
                return max(lf,rf);
            }
        }
        return n;
    }
};