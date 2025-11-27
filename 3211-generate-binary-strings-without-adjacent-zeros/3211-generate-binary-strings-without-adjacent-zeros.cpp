class Solution {
public:
void call(int i,int n1,string s,int &n,unordered_set<string>&ans)
{
    if(i>=n)
    {
        
        ans.insert(s);
        return;
    }
    
    call(i+1,n1+1,s+'1',n,ans);
    if(s[i-1]!='0')
    call(i+1,n1,s+'0',n,ans);

}
    vector<string> validStrings(int n) 
    {
        unordered_set<string>ans;
        call(1,0,"0",n,ans);
        call(1,1,"1",n,ans);
        vector<string>ans1;
        for(auto it: ans)
        ans1.push_back(it);
        return ans1;
        
    }
};