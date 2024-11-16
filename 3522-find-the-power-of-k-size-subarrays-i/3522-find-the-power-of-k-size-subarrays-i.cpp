class Solution {
public:
bool check(int n,vector<int> &nums,int k,int i)
{
    // cout<<i-k+1<<" "<<i<<" *";
    for(int j=i-k+1;j<i;j++)
    {
        if(nums[j]!=nums[j+1]-1)
        {
            // cout<<nums[i]<<" "<<nums[i+1]<<" ";
        return 0;
        }
    }
    return 1;
}
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        vector<int> ans;
        int n=nums.size();
        for(int i=k-1;i<n;i++)
        {
            
                // cout<<i<<" ";
            if(check(n,nums,k,i))
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};