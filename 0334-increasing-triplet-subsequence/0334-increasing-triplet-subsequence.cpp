class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ll(n);
        vector<int> rr(n);
        ll[0]=nums[0];
        rr[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            ll[i]=min(ll[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rr[i]=max(rr[i+1],nums[i]);
        }
        for(int j=1;j<n-1;j++)
        {
            if(ll[j-1]<nums[j] && rr[j+1]>nums[j])
            return 1;
        }
        return 0;
    }
};