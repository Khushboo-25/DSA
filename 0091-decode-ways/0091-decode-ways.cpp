class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] - '0' == 0){
            return 0;
        }
        vector<int> dp(n+2 , 0);
        dp[0] =1;
     
        for(int i = 0 ; i< n ; i++){
            
          if(s[i] != '0'){        
            dp[i+1] += dp[i];
           if( i+1<n && ((s[i] -'0')*10 + s[i+1] - '0') <=26 ){
              dp[i+2] += dp[i];
            }
         }
        }
        return dp[n];
    }
};