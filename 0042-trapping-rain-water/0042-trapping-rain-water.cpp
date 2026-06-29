class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        vector<int>hl(n,0);
        vector<int>hr(n,0);
        hl[0]=height[0];
        hr[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            hl[i]=max(hl[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            hr[i]=max(hr[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(hl[i],hr[i])-height[i];
        }
        return ans;
    }
};