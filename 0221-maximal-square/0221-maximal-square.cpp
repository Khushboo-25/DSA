class Solution {
public:
    int solve(vector<vector<char>>& matrix,int ind,int col,int &ans,vector<vector<int>>&dp)
    {
        if(ind >= matrix.size() || col >= matrix[0].size())
        {
            return 0;
        }

         if(dp[ind][col] != -1)
            return dp[ind][col];

        int right = solve(matrix,ind,col+1,ans,dp);
        int down = solve(matrix,ind+1,col,ans,dp);
        int diagonal = solve(matrix,ind+1,col+1,ans,dp);


       

        if(matrix[ind][col] == '1')
        {
            dp[ind][col] =  1 + min(right,min(down,diagonal));
            
            ans = max(dp[ind][col],ans);
            return dp[ind][col];
        }
        else
            return  dp[ind][col] = 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int n1=solve(matrix,0,0,ans,dp);
        return ans*ans;
        // for(int i = n-1;i>=0;i--)
        // {
        //     for(int j = m-1;j>=0;j--)
        //     {
        //         int right = dp[i][j+1];
        //         int down = dp[i+1][j];
        //         int diagonal = dp[i+1][j+1];
                    

        //         if(matrix[i][j] == '1')
        //         {
        //             dp[i][j] =  1 + min(right,min(down,diagonal));

        //             ans = max(dp[i][j],ans);
        //         }
        //         else
        //             dp[i][j] = 0;
        //     }
        // }
        // return ans*ans;
    }
};