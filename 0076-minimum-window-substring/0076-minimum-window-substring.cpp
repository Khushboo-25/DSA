class Solution {
public:
int check(int m ,string &st,int &sn,unordered_map<char,int> &pt,unordered_map<char,int> ps)
{
    int ans=0;
    for(int i=0;i<m;i++)
    {
        ps[st[i]]++;
    }

    for(int i=m-1;i<sn;i++)
    {
        int f=0;
        for(auto it:pt)
        {
            if(ps[it.first]<it.second)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            return i-m+2;
        }
        if(i+1<sn)
        ps[st[i+1]]++;
        ps[st[i-m+1]]--;
    }
    return ans;

}
    string minWindow(string st, string tt) 
    {
        int sn=st.size(),tn=tt.size();
        int s=tn,e=sn;
        string ans="";
        if(sn<tn)
        return ans;
        unordered_map<char,int>pt,ps;
        for(auto it:tt)
        pt[it]++;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            int i=check(m,st,sn,pt,ps);
            if(i)
            {
                ans=st.substr(i-1,m);
                e=m-1;
            }
            else
            {
                s=m+1;
            }
            
        }
        return ans;
    }
};