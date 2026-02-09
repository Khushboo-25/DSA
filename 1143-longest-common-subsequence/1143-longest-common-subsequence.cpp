class Solution {
public:

int call(string &t1,string &t2,int &n1,int &n2)
{
    vector<vector<int> > tp(n1+1,vector<int> (n2+1,0));
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(t1[i-1]==t2[j-1])
            {
                tp[i][j]=tp[i-1][j-1]+1;
            }
            else
            {
                tp[i][j]=max(tp[i-1][j],tp[i][j-1]);
            }
        }
    }
    return tp[n1][n2];
}
    int longestCommonSubsequence(string t1, string t2) 
    {
       int n1=t1.size(),n2=t2.size();
       return call(t1,t2,n1,n2);
        
    }
};