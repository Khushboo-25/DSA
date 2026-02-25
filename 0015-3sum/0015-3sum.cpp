class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>>st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int tt=0-nums[i]-nums[j];
                int s=j+1;
                int e=n-1;
                while(s<=e)
                {
                    int m=s+(e-s)/2;
                    if(nums[m]==tt)
                    {
                        st.insert({nums[i],nums[j],nums[m]});
                        break;
                    }
                    if(tt>nums[m])
                    {
                        s=m+1;
                    }
                    else
                    e=m-1;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it:st)
        ans.push_back(it);
        return ans;
        
    }
};