class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        unordered_map<int,int>pp;
        for(auto it: arr)
        {
            if(it<0)
            {
                pp[abs(k+it%k)%k]++;
                // cout<<it<<","<<abs(k+it%k)%k<<" ";
            }
            else
            {
            pp[it%k]++;
            // cout<<it<<","<<it%k<<" ";
            }
        }
        int ans=0;
        for(auto it: pp)
        {
            if(it.first!=0)
            {
                if(pp[k-it.first]!=it.second)
                return 0;
            }
            else if(it.first==0)
            {
                if(it.second%2!=0)
                return 0;
            }
        }
        return 1;
        
    }
};