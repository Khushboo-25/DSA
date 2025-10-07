class Solution {
public:
    int maxProfit(vector<int>& a) 
    {
        int mn=a[0];
        int n=a.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            ans=max(a[i]-mn,ans);
            mn=min(a[i],mn);
        }
        return ans;
    }
};