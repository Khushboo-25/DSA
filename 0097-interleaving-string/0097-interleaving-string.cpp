class Solution {
public:
int n1,n2,n3;
bool call(int i,int j,int l,string s1,string s2,string s3,vector<vector<vector<int>>>&dp)
{
    if(j==n1)
    return s3.substr(i)==s2.substr(l);
    else if(l==n2)
    return s3.substr(i)==s1.substr(j);
    if(dp[i][j][l]!=-1)
    return dp[i][j][l];
    if(s1[j]!=s2[l])
    {
        if(s1[j]==s3[i])
        return dp[i][j][l]=call(i+1,j+1,l,s1,s2,s3,dp);
        else if(s2[l]==s3[i])
        return dp[i][j][l]=call(i+1,j,l+1,s1,s2,s3,dp);
        else 
        return dp[i][j][l]=0;
    }
    else
    {
        if(s3[i]!=s1[j]) 
        return dp[i][j][l]=0;
        return dp[i][j][l]=call(i+1,j+1,l,s1,s2,s3,dp)|call(i+1,j,l+1,s1,s2,s3,dp);

    }
}

    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.size();
        n2 = s2.size();
        n3 = s3.size();

        // Check if the lengths don't match
        if (n1 + n2 != n3) return false;

        // Create a 2D DP table
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Initialize the base case
        dp[0][0] = 1;

        // Fill the first row (when using only characters from s2)
        for (int j = 1; j <= n2; ++j) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // Fill the first column (when using only characters from s1)
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        // The answer is in the bottom-right corner of the DP table
        return dp[n1][n2];
    }
};