class Solution {
public:
void call(int i,int &n,vector<int>&nums,vector<int>&a,unordered_map<int,bool>&pp,set<vector<int>>&ans)
{
    if(i>=n)
    {
        ans.insert(a);
        
    }
    for(int j=0;j<n;j++)
    {
        if(pp[j]!=1)
        {
            a.push_back(nums[j]);
            pp[j]=1;
            call(i+1,n,nums,a,pp,ans);
            pp[j]=0;
            a.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) 
    {
        unordered_map<int,bool>pp;
        int n=nums.size();
        set<vector<int>>ans;
        vector<int>a;
        call(0,n,nums,a,pp,ans);
        vector<vector<int>>ans1;
        for(auto it:ans)
        {
            ans1.push_back(it);
        }
        return ans1;

        
    }
};