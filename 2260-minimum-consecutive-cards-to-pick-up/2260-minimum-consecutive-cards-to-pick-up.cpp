class Solution {
public:
bool call(int &sz,int &n,vector<int>&a)
{
    unordered_map<int,int>pp;
    for(int i=0;i<sz;i++)
    {
        pp[a[i]]++;
    }
    if(pp.size()<sz)
    return 1;
    for(int i=sz;i<n;i++)
    {
        pp[a[i]]++;
        if(pp[a[i-sz]]==1)
        {
            pp.erase(a[i-sz]);
        }
        else
        pp[a[i-sz]]--;
        if(pp.size()<sz)
        return 1;
    }
    return 0;
}
    int minimumCardPickup(vector<int>& cards) 
    {
        int n=cards.size();
        int ans=n+1;
        int s=1,e=n;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(call(m,n,cards))
            {
                ans=m;
                e=m-1;
            }
            else
            s=m+1;
        }
        if(ans==n+1)
        return -1;
        return ans;
    }
};