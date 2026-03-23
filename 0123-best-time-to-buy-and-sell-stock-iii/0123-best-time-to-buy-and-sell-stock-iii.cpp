class Solution {
public:
    int maxProfit(vector<int>& ar) 
    {
        int n=ar.size();
        vector<int>pr(n,0);
        int mn=ar[0];
        for(int i=1;i<n;i++)
        {
            pr[i]=max(pr[i-1],ar[i]-mn);
            mn=min(mn,ar[i]);
        }
        vector<int>pl(n,0);
        mn=ar[n-1];
        for(int i=n-2;i>=0;i--)
        {
            pl[i]=max(pl[i+1],mn-ar[i]);
            mn=max(mn,ar[i]);
        }
        int ans=*max_element(pr.begin(),pr.end());
        for(auto it:pl)
        {
            ans=max(ans,it);
        }
        for(int i=1;i<=n-3;i++)
        {
            ans=max(pr[i]+pl[i+1],ans);

        }
        return ans;
        
    }
};