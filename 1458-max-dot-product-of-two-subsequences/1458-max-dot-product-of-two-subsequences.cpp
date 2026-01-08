class Solution {
public:
int call(int i, int j, vector<int>& a, vector<int>& b, vector<vector<int>>& dp) {
    if (i == a.size() || j == b.size()) return -1e8;
    if (dp[i][j] != INT_MIN) return dp[i][j];

    int take = a[i]*b[j] + max(0, call(i+1, j+1, a, b, dp));
    int skipA = call(i+1, j, a, b, dp);
    int skipB = call(i, j+1, a, b, dp);

    return dp[i][j] = max({take, skipA, skipB});
}

    int maxDotProduct(vector<int>&a, vector<int>&b) 
    {
        int n=a.size(),m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
        return call(0,0,a,b,dp);
    }
};