class Solution {
public:
void call(vector<vector<int>>&ans,vector<int> s,vector<int> &arr,int tt,int &n,int i)
{
    
    if(tt<0)
    return;
    if(tt==0)
    {
        ans.push_back(s);
        return;
    }
    for(int j=i;j<n;j++)
    {
        s.push_back(arr[j]);
        call(ans,s,arr,tt-arr[j],n,j);
        s.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& arr, int &tt) 
    {
        int n=arr.size();
        vector<vector<int>> ans;
        vector<int> s;
        call(ans,s,arr,tt,n,0);
	    return ans;
    }
};