class Solution {
public:
    int findMin(vector<int>& a) 
    {
        int n=a.size();
        int s=0,e=n-1;
        int ans=a[n-1];
        while(s<e)
        {
            int m=s+(e-s)/2;
            
            if(a[s]>a[e])
            {
                if(a[m]<a[e])
                {
                    e=m;
                    ans=min(a[m],ans);
                }
                else
                {
                    s=m+1;
                }
            }
            else
            {
                ans=min(a[s],ans);
                e=s;
            }
        }
        return ans;

    }
};