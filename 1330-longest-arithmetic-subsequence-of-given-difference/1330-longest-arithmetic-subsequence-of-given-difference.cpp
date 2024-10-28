class Solution {
public:
int call(int i,int prev,vector<int> &arr,int &n,int &diff, vector<vector<int>>&dp)
{
    if(i>=n)
    return 0;
    if(dp[prev+1][i]!=-1)
    return dp[prev+1][i];
    if(prev==-1)
    {
        int m1=1+call(i+1,i,arr,n,diff,dp);
        int m2=call(i+1,prev,arr,n,diff,dp);
        return dp[prev+1][i]=max(m1,m2);
    }
    else if(arr[i]-arr[prev]==diff)
    {
        int m1=1+call(i+1,i,arr,n,diff,dp);
        int m2=call(i+1,prev,arr,n,diff,dp);
        return dp[prev+1][i]=max(m1,m2);
    }
    return call(i+1,prev,arr,n,diff,dp);
    
}
    
        int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp; // Stores the longest subsequence ending with each value
        int maxLength = 0;

        for (int num : arr) {
            // If num - diff exists, extend that subsequence, otherwise start a new one
            dp[num] = dp[num - diff] + 1;
            maxLength = max(maxLength, dp[num]); // Update max length
        }

        return maxLength;
    }
        
};