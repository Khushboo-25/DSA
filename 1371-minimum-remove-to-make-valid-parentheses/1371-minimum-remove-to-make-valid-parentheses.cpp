class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!='(' && s[i]!=')')
            continue;
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    if(s[st.top()]=='(')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(i);
                    }
                }
                else
                {
                    st.push(i);
                }
            }
        }
        string ans="";
        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty() && st.top()==i)
            {
                st.pop();
            }
            else
            {
                ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};