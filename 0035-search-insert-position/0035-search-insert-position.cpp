class Solution {
public:
bool check(int i,int &n,vector<int> &nums,int &tt)
{
    if(i>=n)
    {
        return 1;
    }
    if(nums[i]>=tt)
    {
        return 1;
    }
    return 0;
}
    int searchInsert(vector<int>& nums, int tt) 
    {
        int n=nums.size();
        int s=0, e=n-1;
        int ans=n;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(check(m,n,nums,tt))
            {
                ans=m;
                e=m-1;
            }
            else
            {
                // ans=m;
                s=m+1;
            }
        }
        return ans;
        
    }
};