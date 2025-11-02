class Solution {
public:
    long long maxProduct(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=LLONG_MIN;
        long long ans1=1e5*1ll*nums[0]*nums[1];
        long long ans2=1e5*1ll*nums[n-2]*nums[n-1];
        long long ans3=-1e5*1ll*nums[0]*nums[n-1];
        ans=max(ans,ans1);
        ans=max(ans,ans2 );
        ans=max(ans,ans3);
        return ans;
    }
};