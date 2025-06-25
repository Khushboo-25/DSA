class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        int ans=0,s=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            ans=min(ans,s);

        }
        return ans>0?0:abs(ans)+1;
        
    }
};