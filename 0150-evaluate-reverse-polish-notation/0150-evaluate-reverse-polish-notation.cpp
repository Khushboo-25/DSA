class Solution {
public:
bool sym(string &s)
{
    if(s.size()==1)
    {
        if(s[0]=='-'||s[0]=='+' || s[0]=='*' || s[0]=='/')
        return 1;
        return 0;

    }
    return 0;
}
int solv(int &ss,int &ff,char &sym)
{
    if(sym=='-')
    {
        return ff-ss;
    }
    if(sym=='+')
    return ff+ss;
    if(sym=='*')
    return ff*ss;
    return ff/ss;
}
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++)
        {
            if(sym(tokens[i]))
            {
                int ss=st.top();
                st.pop();
                int ff=st.top();
                st.pop();
                int nw=solv(ss,ff,tokens[i][0]);
                st.push(nw);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};