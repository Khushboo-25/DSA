class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) 
    {
        int n=a.size();
        vector<int>c(n,0);
        
        unordered_map<int,int>pp1,pp2;
        for(int i=0;i<n;i++)
        {
            pp1[a[i]]++;
            pp2[b[i]]++;
            int ans=0;
            for(auto it:pp1)
            {
                ans+=min(it.second,pp2[it.first]);
            }
            c[i]=ans;
        }
        return c;
        
    }
};