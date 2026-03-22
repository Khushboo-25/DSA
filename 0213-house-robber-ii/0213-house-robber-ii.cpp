class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        return nums[0];
        int p1=nums[0],p2=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++)
        {
            int t1=max(p1+nums[i],p2);
            p1=p2;
            p2=t1;
        }
        int ans=p2;
        p1=max(nums[n-2],nums[n-1]),p2=nums[n-1];
        for(int j=n-3;j>0;j--)
        {
            int t1=max(p2+nums[j],p1);
            p2=p1;
            p1=t1;
        }
        return max(ans,p1);
    }
};