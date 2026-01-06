class Solution {
public:
    int numberOfMatches(int n) 
    {
        vector<int>ans(n+1,INT_MAX);
        ans[0]=0;
        ans[1]=0;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
            ans[i]=min(ans[i],i/2+ans[i/2]);
            else
            ans[i]=min(ans[i],i/2+ans[(i-1)/2+1]);
        }
        // 14->7->4->2-
        return ans[n];
    }
};