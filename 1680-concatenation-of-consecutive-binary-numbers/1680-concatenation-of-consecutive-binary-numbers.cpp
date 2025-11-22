class Solution {
public:
int mod=1e9+7;
string call(int num)
{
    string ans="";
    while(num)
    {
        if(num%2==0)
        ans+='0';
        else
        ans+='1';
        num=num/2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
    int concatenatedBinary(int n) 
    {
        // 32*1e5
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            string st=call(i);
            // cout<<st<<" ";
            for(auto it:st)
            {
                // if(it=='0')
                ans=(ans<<1)%mod;
                if(it=='1')
                ans=(ans+1)%mod;
            }

        }
        return ans;

        
    }
};