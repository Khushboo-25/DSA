class Solution {
public:

void gener(int &n,vector<int> perm,set<vector<int>> &ans,unordered_map<int,bool>app,vector<int> &nums)
{
    if(perm.size()==n)
    {
        ans.insert(perm);
        return ;
    }
    
    for(int i=0;i<n;i++)
    {
        // gener(cr,n,perm,ans,app);
        if(app[i]==false)
        {
            app[i]=true;
            perm.push_back(nums[i]);
            gener(n,perm,ans,app,nums);
            app[i]=false;
            perm.pop_back();
        }
    }
    // gener(cr+1,n,perm,ans);
    // perm.push
}
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        int n=nums.size();
        set<vector<int>>ans;
        vector<vector<int>>ans1;
        vector<int>perm;
        // int cr=0;
        unordered_map<int,bool>app;
        gener(n,perm,ans,app,nums);
        for(auto it:ans)
        {
            ans1.push_back(it);
        }
        return ans1;

    }
};