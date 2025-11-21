class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        unordered_map<char,int>pp;
        for(auto it: s)
        {
            pp[it]++;
        }
        int n=s.size();
        unordered_map<char,int>lf;
        lf[s[0]]++;
        if(pp[s[0]]>1)
        {
            pp[s[0]]--;
        }
        else
        pp.erase(s[0]);
        unordered_set<int> ans;
        for(int i=1;i<n-1;i++)
        {
            if(pp[s[i]]>1)
            {
                pp[s[i]]--;
            }
            else
            pp.erase(s[i]);
            for(char c='a';c<='z';c++)
            {
                if(lf[c]>=1 && pp[c]>=1)
                {
                    // string nw="";
                    // nw+=c+s[i]+c;
                    long long nw=27*27*1ll*(c-'a')+27*1ll*(s[i]-'a')+(c-'a');
                    ans.insert(nw);
                }
            }
            lf[s[i]]++;
        }
        return ans.size();
        
        
    }
};