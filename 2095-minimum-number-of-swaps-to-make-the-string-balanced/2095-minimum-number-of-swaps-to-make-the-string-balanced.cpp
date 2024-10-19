class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                st.push('[');
            }
            else if(s[i]==']')
            {
                if(!st.empty())
                {
                    if(st.top()=='[')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }

        return (st.size()/2+1)/2;
        
    }
};