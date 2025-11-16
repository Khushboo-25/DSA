class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sd) 
    {
        int c0=0,c1=0;
        for(auto it: st)
        {
            if(it==1)
            {
                c1++;
            }
            else
            {
                c0++;
            }
        }
        queue<int>qt;
        stack<int>stk;
        for(auto it:st)
        {
            qt.push(it);
        }
        int n=st.size();
        for(int i=0;i<n;i++)
        {
            stk.push(sd[n-1-i]);
        }
        int ans=st.size();
        while(!stk.empty())
        {
            if(stk.top()==1)
            {
                if(c1>0)
                {
                    while(!qt.front()==1)
                    {
                        int s1=qt.front();
                        qt.pop();
                        qt.push(s1);
                    }
                    qt.pop();
                    ans--;
                    c1--;
                    stk.pop();
                }
                else
                break;
            }
            else
            {
                if(c0>0)
                {
                    while(!qt.front()==0)
                    {
                        int s1=qt.front();
                        qt.pop();
                        qt.push(s1);
                    }
                    qt.pop();
                    ans--;
                    c0--;
                    stk.pop();
                }
                else
                break;
            }
        }
        return ans;
    }
};