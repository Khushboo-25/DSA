class Solution {
public:
    long long dividePlayers(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int sum=a[0]+a[n-1];
        long long ans=0;
        for(int i=0;i<n/2;i++)
        {
            if(a[i]+a[n-1-i]!=sum)
            return -1ll;
            ans+=1ll*a[i]*a[n-1-i];
        }
        return ans;
        
    }
};