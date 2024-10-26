class Solution {
public:
void call(int i,int prev,int &n,string &s,unordered_map<string,int>&pp,vector<string>&ans,string u)
{
    string cr=s.substr(prev-1+1,i-prev+1);
    // cout<<cr<<" ";
    
    if(i>=n)
    {
        if(pp[cr]==1)
        {
            u+=cr;
            ans.push_back(u);
            return;
        }
        return;
    }
    // if(dp[i][prev]!=-1)
    // return dp[i][prev];
    // bool f=0;
    if(pp[cr]>0)
    {
        call(i+1,i+1,n,s,pp,ans,u+cr+' ');
    }
    call(i+1,prev,n,s,pp,ans,u);
    // return dp[i][prev]=f;
    
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>pp;
        
        for(auto it:wordDict)
        {
            pp[it]=1;
            // cout<<it<<" *";
        }
        int n=s.size();
        vector<string>ans;
        string u="";
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
         call(0,0,n,s,pp,ans,u);
         return ans;
    }
};