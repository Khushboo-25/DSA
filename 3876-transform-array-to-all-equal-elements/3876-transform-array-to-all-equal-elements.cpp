class Solution {
public:
bool check(int c,vector<int>nums,int k)
{
    int n=nums.size();
    int cn=0;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]!=c)
        {
            cn++;
            nums[i]=-1*nums[i];
            nums[i+1]=-1*nums[i+1];
        }
    }
    if(nums[n-1]!=c)
    {
        return 0;
    }
    if(cn<=k)
    return 1;
    return 0;
}
    bool canMakeEqual(vector<int>& nums, int k) 
    {
        return check(1,nums,k)|check(-1,nums,k);
    }
};