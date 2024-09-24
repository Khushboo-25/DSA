class Solution {
public:
vector<int> plen(string s,int i,int j,int n)
{
    // int i=0,j=n-1;
    while(i>=0 && j<n )
    {
        if(s[i]==s[j])
            i--,j++;
            else
            break;
        }

        return {i+1,j-i-1};
    
}
    string longestPalindrome(string s) 
    {
        string res="";
        int l=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            vector<int> x=plen(s,i,i,n);
            if(x[1]>l)
            {
                res=s.substr(x[0],x[1]);
                l=x[1];
            }
            x=plen(s,i,i+1,n);
            if(x[1]>l)
            {
                res=s.substr(x[0],x[1]);
                l=x[1];
            }
        }
        return res;
    }
};