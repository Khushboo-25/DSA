class Solution {
public:
    int countDays(int days, vector<vector<int>>& mt) 
    {
        sort(mt.begin(),mt.end());
        stack<pair<int,int>>st;
        int n=mt.size();
        st.push({mt[0][0],mt[0][1]});
        for(int i=0;i<n;i++)
        {
            int s2=mt[i][0];
            int e2=mt[i][1];
            while(!st.empty())
            {
                int s1=st.top().first;
                int e1=st.top().second;
                if(e1>=s2)
                {
                    s2=s1;
                    e2=max(e1,e2);
                    st.pop();
                }
                else
                break;
            }
            st.push({s2,e2});
        }
        int cn=0;
        while(!st.empty())
        {
            int s1=st.top().first;
            int e1=st.top().second;
            // cout<<s1<<" "<<e1<<endl;
            cn+=e1-s1+1;
            st.pop();
        }
        return days-cn;
        
    }
};