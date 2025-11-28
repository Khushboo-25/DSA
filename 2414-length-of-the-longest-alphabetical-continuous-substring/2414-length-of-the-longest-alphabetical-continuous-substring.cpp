class Solution {
public:
    int longestContinuousSubstring(string s) 
    {
        int n=s.size();
        vector<int>a(n,0);
        // int ans=0;
        
            a[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]-s[i-1]==1 && a[i-1]!=0)
            {
                a[i]=a[i-1]+1;
            }
            else
            {
                a[i]=1;
            }
        }
        return *max_element(a.begin(),a.end());
        
    }
};