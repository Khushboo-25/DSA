class Solution {
public:
    int maximumSum(vector<int>& arr) 
    {
        int n=arr.size();
        if(n==1)
        return arr[0];
        vector<int>sm(n+1,INT_MIN);
        sm[1]=arr[0];
        
        int s=arr[0];
        for(int i=2;i<=n;i++)
        {
            if(s+arr[i-1]<=arr[i-1])
            {
                sm[i]=max({sm[i],arr[i-1]});
                s=arr[i-1];
            }
            else
            {
                sm[i]=max({sm[i],s+arr[i-1]});
                s+=arr[i-1];
            }
        }
        vector<int>pm(n+2,INT_MIN);
        pm[n]=arr[n-1];
        s=pm[n];
        for(int i=n-1;i>=1;i--)
        {
            if(s+arr[i-1]<=arr[i-1])
            {
                pm[i]=max(pm[i],arr[i-1]);
                s=arr[i-1];
            }
            else
            {
                pm[i]=max(pm[i],s+arr[i-1]);
                s+=arr[i-1];
            }
        }
        int mx1=*max_element(sm.begin(),sm.end());
        int mx2=*max_element(pm.begin(),pm.end());
        int ans=max(mx1,mx2);
    
        for(int i=1;i<=n;i++)
        {
            int s1=0;
            if(i+1<=n)
            s1+=pm[i+1];
            if(i-1>=1)
            {
                s1+=sm[i-1];
            }
            ans=max(ans,s1);
        }
        return ans;
        
    }
};