class Solution {
public:
int mod=1e9+7;
    int trailingZeroes(int n) 
    {
        vector<pair<int,int>> count;
        count.push_back({0,0});
        int n2=0,n5=0;
        for(int i=1;i<=n;i++)
        {
            int ans2=0;
            if(i%2==0)
            {
                ans2=(ans2+count[i/2].first%mod)%mod+1;
            }
            int ans5=0;
            if(i%5==0)
            {
                ans5=(ans5+count[i/5].second%mod)%mod+1;
            }
            count.push_back({ans2,ans5});
            n2=n2+count[i].first;
            n5=n5+count[i].second;
            // cout<<ans2<<" "<<ans5<<endl;
        }
        
        
        return min(n2,n5);
        
    }
};

