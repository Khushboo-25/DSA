class Solution {
public:
    int longestBalanced(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        unordered_set<int>ev,od;
        for(int i=0;i<n;i++)
        {
            ev.clear();
            od.clear();
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2==0)
                ev.insert(nums[j]);
                else
                od.insert(nums[j]);
                if(ev.size()==od.size())
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};