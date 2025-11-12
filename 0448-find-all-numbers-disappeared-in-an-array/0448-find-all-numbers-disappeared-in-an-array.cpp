class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        vector<bool>ans(n,0);
        for(auto it:nums)
        {
            ans[it-1]=1;
        }
        vector<int>ns;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0)
            ns.push_back(i+1);
        }
        return ns;
        
    }
};