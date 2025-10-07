class Solution {
public:
bool call(int s,vector<int> &pl,int &n,int &h)
{
    int tm=0;
    for(auto it: pl)
    {
        tm+=(it+s-1)/s;
        if(tm>h)
        return 0;
    }
    return 1;
}
    int minEatingSpeed(vector<int>& pl, int &h) 
    {
        int ans=INT_MAX;
        int s=1,e=INT_MAX;
        int n=pl.size();
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(call(m,pl,n,h))
            {
                ans=m;
                e=m-1;
            }
            else
            s=m+1;
        }
        return ans;
        
    }
};