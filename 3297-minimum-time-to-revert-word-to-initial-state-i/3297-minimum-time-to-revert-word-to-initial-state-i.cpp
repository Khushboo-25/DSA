class Solution {
public:
    int minimumTimeToInitialState(string cr, int k) 
    {
        int un=0;
        string st=cr;
        un+=k;
        int n=cr.size();
        // if(n%k!=0)
        // return -1;
        st=st.substr(k);
        // cout<<st;
        int t=1;
        while(1)
        {
            int m=st.size();
            if(m+un==n && st==cr.substr(0,m))
            return t;
            if(st.size()<k)
            {
                st="";
            }
            else
            st=st.substr(k);
            un+=min(k,m);
            t++;
        }
        return t;
    }
};