class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) 
    {
        int n=t.size();
        if(n==1)
        return t[0][0];
        int k=1,l=1;
        int ans=INT_MAX;
        while(k<n)
        {
            t[k][0]+=t[k-1][0];
            t[k][l]+=t[k-1][l-1];
            for(int i=1;i<l;i++)
            {
               
                t[k][i]+=min(t[k-1][i-1],t[k-1][i]);
                if(k==n-1)
                {
                    ans=min(t[k][i],ans);

                }
                
            }
            l++;
            k++;
            

        }
        ans=min(t[k-1][0],ans);
        ans=min(t[k-1][l-1],ans);
        return ans;

        
    }
};