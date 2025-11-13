class Solution {
public:
vector<int> abr(string st)
{
    int id=0;
    int n=st.size();
    int i=0;
    int m=0;
    while(st[i]!=':')
    {
        id=id*10+(st[i]-'0');
        i++;
    }
    i++;
    if(st[i]=='s')
    {
        m=1;
    }
    while(st[i]!=':')
    {
        i++;
    }
    i++;
    int tl=0;
    while(i<n)
    {
        tl=tl*10+(st[i]-'0');
        i++;
    }
    return {id,m,tl};
}
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        vector<int>ans(n,0);
        int mn=logs.size();
        vector<vector<int>>pp;
        for(int i=0;i<mn;i++)
        {
            vector<int>pi=abr(logs[i]);
            pp.push_back(pi);
        }
        int last=0;
        stack<int>st;
        for(int i=0;i<mn;i++)
        {
            int id=pp[i][0];
            int op=pp[i][1];
            int tk=pp[i][2];
            if(op)// start
            {
                if(!st.empty())
                {
                    ans[st.top()]+=tk-last;
                }
                st.push(id);
                last=tk;
            }
            else //end
            {
                if(!st.empty())
                {
                    ans[st.top()]+=tk-last+1;
                    st.pop();
                }
                last=tk+1;
            }
            
        }
        return ans;
    }
};