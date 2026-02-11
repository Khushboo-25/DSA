class Solution {
public:
bool call(int sum,vector<int>&nums,int&n,int &k)
{
    int cn=0;
    int cs=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>sum)
        return 0;
        if(cs+nums[i]>sum)
        {
            cn++;
            cs=nums[i];
        }
        else
        cs+=nums[i];
        

    }

    if( cn+1>k)
    return 0;
    return 1;
}
    int splitArray(vector<int>& nums, int k) 
    {
        int ans=1e9;
        int n=nums.size();
        int s=0,e=1e9;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(call(m,nums,n,k))
            {
                ans=m;
                e=m-1;
            }
            else
            s=m+1;
        }
        return ans;
        
    }
};