class Solution {
public:
void call(int i,int n,int k,vector<int> &a,vector<vector<int>>&ans)
{
    if(k==0)
    {
        ans.push_back(a);
        return;
    }
    if(i>n)
    return;
    
        call(i+1,n,k,a,ans);
        a.push_back(i);
        call(i+1,n,k-1,a,ans);
        a.pop_back();
}
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>a;
        vector<vector<int>>ans;
        call(1,n,k,a,ans);
        return ans;
        
    }
};