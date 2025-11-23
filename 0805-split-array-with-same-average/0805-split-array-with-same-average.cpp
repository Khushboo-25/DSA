// class Solution {
// public:
// int call(int rm,int i,int cn,int &n,int &sm,vector<int>&nums,unordered_map<string,int>&dp)
// {
//     if(i>=n)
//     {
//         long long sm1=1ll*rm*(n-cn);
//         long long sm2=1ll*(sm-rm)*(cn);
//         if(cn!=n && cn!=0 && sm1==sm2)
//         return 1;
//         return 0;
//     }
//     string fs=to_string(rm)+','+to_string(i)+','+to_string(cn);
    
//     if(dp.find(fs)!=dp.end())
//     return dp[fs];
//     if(call(rm+nums[i],i+1,cn+1,n,sm,nums,dp))
//     return dp[fs]=1;
//     if(call(rm,i+1,cn,n,sm,nums,dp))
//     return dp[fs]=1;
//     return dp[fs]=0;
    
// }
//     bool splitArraySameAverage(vector<int>& nums) 
//     {
//         int n=nums.size();
//         int sm=0;
//         for(auto it: nums)
//         {
//             sm+=it;
//         }
//         unordered_map<string,int>dp;
//         if(call(0,0,0,n,sm,nums,dp)==1)
//         return 1;
//         return 0;
        
//     }
// };

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) 
    {
        int n = nums.size();
        int sm = accumulate(nums.begin(), nums.end(), 0);

        sort(nums.begin(), nums.end());

        vector<vector<bool>> dp(n+1, vector<bool>(sm+1, false));
        dp[0][0] = true;

        for (int x : nums)
        {
            for (int k = n-1; k >= 0; --k)
            {
                for (int s = sm - x; s >= 0; --s)
                {
                    if (dp[k][s])
                        dp[k+1][s+x] = true;
                }
            }
        }

        for(int k = 1; k < n; k++)
        {
            if ((sm * k) % n != 0) continue;

            int target = (sm * k) / n;
            if (dp[k][target]) return true;
        }

        return false;
    }
};
