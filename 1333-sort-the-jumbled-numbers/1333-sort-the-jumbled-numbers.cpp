#include<bits/stdc++.h>
class Solution {
public:
int call(int k,vector<int>&pp)
{
    string ms=to_string(k);
    string ans="";
    for(auto it: ms)
    {
        char c='0';
        c+=pp[it-'0'];
        ans+=c;
    
    }
    // reverse(ans.begin(),ans.end());
    int n1=0;
    for(auto it:ans)
    {
        n1=n1*(10)+(it-'0');
    }
    return n1;
}
    vector<int> sortJumbled(vector<int>& pp, vector<int>&a) 
    {
        vector<pair<int,int>>nw;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            int n1=call(a[i],pp);
            nw.push_back({n1,i});
            // cout<<n1<<" "<<a[i]<<endl;
        }
        sort(nw.begin(),nw.end());
        vector<int>ans;
        for(auto it: nw)
        {
            // cout<<it.first<<" "<<it.second<<endl;
            ans.push_back(a[it.second]);
        }
        return ans;

        
    }
};