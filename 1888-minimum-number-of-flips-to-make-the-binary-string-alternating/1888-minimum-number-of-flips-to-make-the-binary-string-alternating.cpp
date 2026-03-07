class Solution {
public:
    int minFlips(string s) 
    {
        int n=s.size();
        vector<vector<int>>pr(n,vector<int>(2,INT_MAX));
        if(s[0]=='0')
        {
            pr[0][0]=0;
            pr[0][1]=1;
        }
        else // 1
        {
            pr[0][0]=1;
            pr[0][1]=0;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                pr[i][0]=min(pr[i][0],pr[i-1][1]);
                pr[i][1]=min(pr[i][1],pr[i-1][0]+1);
            }
            else //1
            {
                pr[i][0]=min(pr[i][0],pr[i-1][1]+1);
                pr[i][1]=min(pr[i][1],pr[i-1][0]);
            }
        }
        vector<vector<int>>sf(n,vector<int>(2,INT_MAX));
        if(s[n-1]=='0')
        {
            sf[n-1][0]=0;
            sf[n-1][1]=1;
        }
        else // 1
        {
            sf[n-1][0]=1;
            sf[n-1][1]=0;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                sf[i][0]=min(sf[i][0],sf[i+1][1]);
                sf[i][1]=min(sf[i][1],sf[i+1][0]+1);
            }
            else //1
            {
                sf[i][0]=min(sf[i][0],sf[i+1][1]+1);
                sf[i][1]=min(sf[i][1],sf[i+1][0]);
            }
        }
        int ans=min(pr[n-1][0],pr[n-1][1]);
        for(int i=0;i<n-1;i++)
        {
            int rf=n-(i+1);
            int lf=i+1;
            if((lf%2==0 && rf%2==0)||(lf%2==1 && rf%2==1)) // even even
            {
                ans=min({ans,pr[i][0]+sf[i+1][1],pr[i][1]+sf[i+1][0]});
            }
            else 
            {
                ans=min({ans,pr[i][0]+sf[i+1][0],pr[i][1]+sf[i+1][1]});
            }

        }
        return ans;
    }
};