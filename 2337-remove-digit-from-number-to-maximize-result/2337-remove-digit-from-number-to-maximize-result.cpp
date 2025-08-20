class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans="";
        int n=number.size();
        for(int i=0;i<n;i++)
        {
            if(number[i]==digit)
            {
                string ts=number.substr(0,i);
                if(i+1<n)
                ts+=number.substr(i+1,n-i-1);
                ans=max(ans,ts);
            }
        }
        return ans;
    }
};