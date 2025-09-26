class Solution {
public:
    long long numberOfWays(string s) 
    {
        int n=s.size();
        vector<vector<int>>ps(n,vector<int>(2,0));
        vector<vector<int>>ss(n,vector<int>(2,0));
        if(s[0]=='0')
        ps[0][0]=1;
        else
        ps[0][1]=1;
        if(s[n-1]=='0')
        ss[n-1][0]=1;
        else
        ss[n-1][1]=1;
        for(int i=1;i<n;i++)
        {
            ps[i][0]=ps[i-1][0];
            ps[i][1]=ps[i-1][1];
            if(s[i]=='1')
            ps[i][1]++;
            else
            ps[i][0]++;
        }
        for(int i=n-2;i>=0;i--)
        {
            ss[i][0]=ss[i+1][0];
            ss[i][1]=ss[i+1][1];
            if(s[i]=='1')
            ss[i][1]++;
            else
            ss[i][0]++;
        }
        long long ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='1')
            {
                ans+=ps[i-1][0]*1ll*ss[i+1][0];
            }
            else
            {
                ans+=ps[i-1][1]*1ll*ss[i+1][1];
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<ps[i][0]<<" "<<ps[i][1]<<endl;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<ss[i][0]<<" "<<ss[i][1]<<endl;
        // }
        return ans;
        
    }
};