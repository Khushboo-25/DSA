class Solution {
public:
int call(int i,int df,vector<int> &nums,int &n)
{
    if(i>=n)
    return 0;
    int cn=0;
    for(int j=i+1;j<n;j++)
    {
        if(nums[j]-nums[j-1]!=df)
        return cn;
        cn++;
    }
    return cn;

}
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int cn=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        cn+=call(i,nums[i]-nums[i-1],nums,n);
        return cn;
    }
};