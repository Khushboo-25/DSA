class Solution {
public:
    int countMatchingSubarrays(vector<int>&a,vector<int>&p)
    {
        int n=a.size();
        int m=p.size();
        int ans=0;
        for(int i=0;i<=n-m-1;i++)
        {
            bool sm=1;
            for(int j=0;j<m;j++)
            {
                if(p[j]==0 && !(a[i+j+1]==a[i+j]))
                {
                    sm=0;
                    break;
                }
                if(p[j]==1 && !(a[i+j+1]>a[i+j]))
                {
                    sm=0;
                    break;
                }
                if(p[j]==-1 && !(a[i+j+1]<a[i+j]))
                {
                    sm=0;
                    break;
                }
            }
            if(sm)
            ans++;

        }
        return ans;
    }
};