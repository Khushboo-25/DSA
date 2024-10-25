class Solution {
public:

    int change(int tt, vector<int>& coins) {

        int n=coins.size();
        vector<vector<int> > pp(n+1,vector<int> (tt+1,0));
        for(int i=0;i<=n;i++) pp[i][0]=1;
        for(int i=1;i<=tt;i++) pp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=tt;j++)
            {
                if(coins[i-1]<=j)
                {
                    pp[i][j]=pp[i][j-coins[i-1]]+pp[i-1][j];
                }
                else{
                    pp[i][j]=pp[i-1][j];
                }
            }
        }
        return pp[n][tt];
    }
};