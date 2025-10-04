class Solution {
public:
int call(string &s)
{
    if(s.substr(1,8)=="00000000")
    return 2;
    else if(s.substr(1,4)=="0000" || s.substr(3,4)=="0000" || s.substr(5,4)=="0000")
    return 1;
    return 0;

}
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) 
    {
        sort(rs.begin(),rs.end());
        int cn=1;
        string s="0000000000";
        int ans=0;
        int m=0;
        for(auto it: rs)
        {
            cout<<it[0]<<" "<<it[1]<<endl;
            int in=it[0];
            int cc=it[1];
            if(in!=cn)
            {
                ans+=call(s);
                m++;
                s="0000000000";
                cn=in;
            }
            s[cc-1]='1';
        }
        ans+=call(s);
        m++;
        return ans+2*(n-m);

        
    }
};