class Solution {
public:
    int mirrorDistance(int n) 
    {
        string ans=to_string(n);
        reverse(ans.begin(),ans.end());
        int n1=0;
        for(auto it:ans)
        {
            n1=n1*10+(it-'0');

        }
        return abs(n-n1);
        
    }
};