class Solution {
public:
void call(string s,int i,int &n,vector<string>&arr,vector<int>&pp,unordered_set<string>&ans)
{
    if(i==n)
    {
        ans.insert(s);
        return;
    }
    call(s,i+1,n,arr,pp,ans);
    int m=0;
    for(auto it:arr[i])
    {
        pp[it-'a']++;
        if(pp[it-'a']>=2)
        {
            m=1;
        }
    }
    if(m==0)
    {
        call(s+arr[i],i+1,n,arr,pp,ans);
    }
    for(auto it:arr[i])
    {
        pp[it-'a']--;
    }
 }
    int maxLength(vector<string>& arr) 
    {
        unordered_set<string>ans;
        vector<int>pp(26,0);
        int n=arr.size();
        call("",0,n,arr,pp,ans);
        int fn=0;

        for(auto it:ans)
        {
            int nm=it.size();
            fn=max(fn,nm);
        }
        return fn;
    }
};