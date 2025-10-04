class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> lf(n,0);
        vector<int>rf(n,0);
        lf[0]=arr[0];
        rf[n-1]=arr[n-1];
        for(int i=1;i<n;i++)
        {
            lf[i]=arr[i]^lf[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            rf[i]=rf[i+1]^arr[i];
        }
        
        unordered_set<string>st;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    int xr1=lf[j-1];
                     if(i-1>=0)
                    {
                        xr1^=lf[i-1];
                    }
                    int xr2=rf[j];
                   
                    if(k+1<n)
                    {
                        xr2^=rf[k+1];
                    }
                    if(xr1==xr2)
                    {
                        string ans=to_string(i)+','+to_string(j)+','+to_string(k);
                        st.insert(ans);
                    }
                }
            }
        }
        return st.size();
    }
};