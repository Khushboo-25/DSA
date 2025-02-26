class Solution {
public:
bool check(int m,int &n,vector<int> &nums)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>=m)
        {
            c++;
            if(c>=m)
            {
                return 1;
            }
        }
    }
    return 0;
}
    int hIndex(vector<int>& nums) 
    {
        
        int ans=0;
        int n=nums.size();
        int s=1,e=n;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(check(m,n,nums))
            {
                ans=m;
                s=m+1;
            }
            else
            {
                e=m-1;
            }
        }
        return ans;

        
    }
};