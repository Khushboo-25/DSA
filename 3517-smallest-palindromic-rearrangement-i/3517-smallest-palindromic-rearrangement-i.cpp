class Solution {
public:
    string smallestPalindrome(string s) 
    {
        sort(s.begin(),s.end());
        string fs="";
        string bs="";
        unordered_map<char,int>pp;
        for(auto it:s)
        pp[it]++;
        string rm="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(pp[s[i]]>=2)
            {
                fs+=s[i];
                bs+=s[i];
                i++;
                if(pp[s[i]]==2)
                pp.erase(s[i]);
                else
                pp[s[i]]-=2;
            }
            else
            {
                rm+=s[i];
            }
        }
        reverse(bs.begin(),bs.end());
        return fs+rm+bs;
        
    }
};