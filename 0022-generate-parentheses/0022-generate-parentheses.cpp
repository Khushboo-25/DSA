class Solution {
public:
void perm(string wt,int op,int cp,set<string> &st,int  n)
{
   if(op==n && cp==n)
   {
       st.insert(wt);
       return;
   } 
   if(op>n || cp>n || op<cp)
   return;
   perm(wt+'(',op+1,cp,st,n);
   perm(wt+')',op,cp+1,st,n);

}
    vector<string> generateParenthesis(int n) 
    {
        string s="";
        set<string> st; 
        int op=0,cp=0;
        perm("",0,0,st,n);
        vector<string> ans;
        for(auto it: st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};