class Solution {
public:
    int maximum69Number (int num) 
    {
        string s=to_string(num);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans*10+(s[i]-'0');
        }
        return ans;
        
    }
};