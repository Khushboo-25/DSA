class Solution {
public:
int call(int i,int j,int &n,vector<vector<int>> &ep,vector<vector<int>>&dp)
{
    if(i>=n)
    return 0;
    if(dp[i][j+1]!=-1)
    return dp[i][j+1];
    int ans=0;
    if(j==-1)
    {
        ans=max(ans,1+call(i+1,i,n,ep,dp));
    }
    else
    {
        if(j!=-1 && ep[i][0]>ep[j][0] && ep[i][1]>ep[j][1])
        {
            ans=max(ans,1+call(i+1,i,n,ep,dp));
        }
    }
    
    ans=max(ans,call(i+1,j,n,ep,dp));
    return dp[i][j+1]=ans;
}
    int maxEnvelopes(vector<vector<int>>& ep) {
    int n = ep.size();

    // Sort by width asc, and if equal, height desc
    sort(ep.begin(), ep.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] > b[1]; // descending height for same width
        return a[0] < b[0];
    });

    // Extract heights
    vector<int> heights;
    for (auto &e : ep) heights.push_back(e[1]);

    // Now apply LIS on heights
    vector<int> dp;
    for (int h : heights) {
        auto it = lower_bound(dp.begin(), dp.end(), h);
        if (it == dp.end()) dp.push_back(h);
        else *it = h;
    }

    return dp.size(); // Length of LIS = max number of envelopes
}

};