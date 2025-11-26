class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) 
    {
        long long ans=0;
        int n=mat.size();
        int ans1=INT_MAX;
        int nv=0,nz=0;
        for(auto it: mat)
        {
            for(auto it1:it)
            {
                ans+=abs(it1);
                ans1=min(ans1,abs(it1));
                if(it1<0)
                {
                    nv++;
                    
                }
                if(it1==0)
                nz++;

            }
        }
        cout<<ans<<" "<<ans1<<" ";
        if(nz>0)
        return ans;
        else if(nv%2==1)
        {
            ans-=2*1ll*(ans1);
        
        }
        
        return ans;



    }
};