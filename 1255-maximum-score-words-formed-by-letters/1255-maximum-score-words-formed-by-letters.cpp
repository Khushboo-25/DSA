class Solution {
public:
int call(int i,int &n,vector<string>&wd,vector<int>&sr,vector<int>&fp)
{
    if(i>=n)
    return 0;
    int tk0=call(i+1,n,wd,sr,fp);
    int tk1=0;
    bool ps=1;
    for(auto it:wd[i])
    {
        fp[it-'a']--;
        if(fp[it-'a']<0)
        {
            ps=0;
        }
        tk1+=sr[it-'a'];
    }
    if(ps==0)
    {
        tk1=0;
    }
    else
    tk1+=call(i+1,n,wd,sr,fp);
    for(auto it:wd[i])
    {
        fp[it-'a']++;
    }
    return max(tk0,tk1);
}
    int maxScoreWords(vector<string>& wd, vector<char>& lt, vector<int>& sr) 
    {
        int n=wd.size();
        vector<int>fp(26,0);
        for(auto it:lt)
        {
            fp[it-'a']++;
        }
        return  call(0,n,wd,sr,fp);
    }
};