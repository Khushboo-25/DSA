class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>&mat,int&tt)
    {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ps(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int psr=ps[i][j+1];
                int psd=ps[i+1][j];
                int psc=ps[i+1][j+1];
                ps[i][j]=mat[i][j]+psr+psd-psc;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int di=i;di<n;di++)
                {
                    for(int dj=j;dj<m;dj++)
                    {
                        int t1=ps[i][j];
                        int tl=ps[i][dj+1];
                        int td=ps[di+1][j];
                        int tc=ps[di+1][dj+1];
                        if(tt==(t1-(tl+td)+tc))
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};