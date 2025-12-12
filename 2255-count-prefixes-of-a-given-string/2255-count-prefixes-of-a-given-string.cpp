class Solution {
public:
    int countPrefixes(vector<string>&wd, string&s)
    {
        int ans=0;
        for(auto it:wd)
        {
            int n=it.size();
            if(it.size()<=s.size())
            {
                bool ps=1;
                for(int i=0;i<n;i++)
                {
                    if(s[i]!=it[i])
                    {
                        ps=0;
                        break;
                    }
                }
                if(ps)
                ans++;
            }
        }
        return ans;
        
    }
};