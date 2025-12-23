class Solution {
public:

    int minimumCardPickup(vector<int>&a) 
    {
        int n=a.size();
        int lt=0;
        int ans=n+1;
        unordered_map<int,int>pp;
        for(int i=0;i<n;i++)
        {
            pp[a[i]]++;
            while(pp.size()<i-lt+1)
            {
                ans=min(ans,i-lt+1);
                if(pp[a[lt]]==1)
                pp.erase(a[lt]);
                else
                pp[a[lt]]--;
                lt++;
            }
        }
        if(ans==n+1)
        return -1;
        return ans;
    }
};