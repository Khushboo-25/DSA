class Solution {
public:
    int maxCoins(vector<int>& p) 
    {
        int n=p.size();
        sort(p.begin(),p.end());
        int t=n/3;
        int e=n-2;
        int ans=0;
        while(t--)
        {
            ans+=p[e];
            e-=2;
        }
        return ans;
        
        
    }
};