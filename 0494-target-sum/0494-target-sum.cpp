class Solution {
public:
int solve(int tt,vector<int> &nums)
{
    int n=nums.size();
    int t[n+1][tt+1];
    // 
    t[0][0]=1;
    for(int i=1;i<=tt;i++)
    {
        t[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=tt;j++)
        {
            if(nums[i-1]<=j)
            {
                t[i][j]=t[i-1][j-nums[i-1]]+ t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][tt];
}
    int findTargetSumWays(vector<int>& nums, int sum2) 
    {
        
        int n=nums.size();
        int sum1=0;
        // int sum2=tt;
        for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
        }
        int d2=(sum1-sum2);
        int d1=(sum1+sum2);
        if( sum2>sum1 || d1%2 || d2%2 )
        return 0;
        return solve(d2/2,nums);

        
    }
};