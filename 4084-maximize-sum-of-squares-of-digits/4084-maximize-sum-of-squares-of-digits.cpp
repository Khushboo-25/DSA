class Solution {
public:
    string maxSumOfSquares(int num, int sum) 
    {
        string ans="";
        while(sum)
        {
            if(sum>=9)
            {
                ans+='9';
                sum-=9;
            }
            else
            {
                char c='0'+sum;
                ans+=c;
                sum=0;
            }
        }
        while(ans.size()<num)
        ans+='0';
        if(ans.size()>num)
        return "";
        return ans;
        
    }
};