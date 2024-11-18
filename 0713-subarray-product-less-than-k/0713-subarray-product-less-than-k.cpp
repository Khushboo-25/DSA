class Solution {
public:
int call(int i,vector<int> &nums,int &n,int &k)
{
    long long pp=nums[i]*1ll;
    if(pp>=k*1ll)
    return 0;
    int cn=1;
    while(i+1<n)
    {
        pp=pp*1ll*nums[i+1];
        if(pp>=k*1ll)
        return cn;
        cn++;
        i++;
    }
    return cn;
}
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int cn=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            cn+=call(i,nums,n,k);
        }
        return cn;
        
    }
};