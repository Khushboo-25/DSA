class Solution {
public:
    vector<int> asteroidCollision(vector<int>& astro) 
    {
        stack<int>st;
        for(auto it: astro)
        {
            if(st.empty())
            {
                st.push(it);

            }
            else if(st.top()>0)
            {
                if(it>0)
                {
                    st.push(it);
                }
                else
                {
                    int c=1;
                    while(!st.empty() && st.top()>0)
                    {
                        int f1=abs(st.top());
                        int f2=abs(it);
                        if(f1>f2)
                        {
                            c=0;
                            break;
                        }
                        else if(f1==f2)
                        {
                            c=0;
                            st.pop();
                            break;
                        }
                        else
                        {
                            st.pop();
                            
                        }
                    }
                    if(c==1)
                    st.push(it);
                }
            }
            else
            {
                st.push(it);
                
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};