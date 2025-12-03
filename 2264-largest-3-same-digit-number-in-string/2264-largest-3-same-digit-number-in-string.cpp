class Solution {
public:
    string largestGoodInteger(string num) 
    {
        string ans="";
        int n=num.size();
        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1] && num[i]==num[i+2])
            ans=max(ans,num.substr(i,3));
        }
        return ans;
        
    }
};