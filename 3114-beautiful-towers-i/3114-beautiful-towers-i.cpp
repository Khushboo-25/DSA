class Solution {
public:
long long calldsc(int s,int aff,vector<int> &a)
{
    if(s<0)
    return 0;
    if(a[s]<a[aff])
    {
        return a[s]+calldsc(s-1,s,a);
    }
    else
    {
        return a[aff]+calldsc(s-1,aff,a);
    }
}
long long callinc(int e,int &n,int prev,vector<int>&a)
{
    if(e>=n)
    return 0;
    if(a[e]<a[prev])
    return a[e]+callinc(e+1,n,e,a);
    return a[prev]+callinc(e+1,n,prev,a);
}
    long long maximumSumOfHeights(vector<int>& a) {
        long long ans=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            long long sumleft=calldsc(i-1,i,a);
            long long sumright=callinc(i+1,n,i,a);
            ans=max(ans,sumleft+sumright+a[i]);

        }
        return ans;
    }
};