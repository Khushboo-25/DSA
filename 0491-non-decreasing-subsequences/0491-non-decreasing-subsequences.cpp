class Solution {
public:
void call(int &n,vector<int>&c,int i,vector<int>&nums,set<vector<int>>&st)
{
    if(i>=n)
    {
        if(c.size()>=2)
        st.insert(c);
        return;
    }
    if(c.back()<=nums[i])
    {
        c.push_back(nums[i]);
        call(n,c,i+1,nums,st);
        c.pop_back();
    }
    call(n,c,i+1,nums,st);
}
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            vector<int>c;
            c.push_back(nums[i]);
            call(n,c,i+1,nums,st);
        }
        vector<vector<int>>ans;
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
        
    }
};