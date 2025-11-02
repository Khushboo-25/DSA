class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
       unordered_map<int,bool>pp;
       for(auto it:nums)
       pp[it]=1;
       int mx=*max_element(nums.begin(),nums.end());
       int mn=*min_element(nums.begin(),nums.end());
       vector<int>ans;

       for(int i=mn;i<=mx;i++)
       {
        if(pp[i]!=1)
        ans.push_back(i);
       }
       return ans;



        
    }
};