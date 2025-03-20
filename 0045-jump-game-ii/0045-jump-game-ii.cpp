class Solution {
public:

    int jump(vector<int>&arr) 
    {
         int n=arr.size();
        vector<int> jp(n,INT_MAX);
        jp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]==0)
            {
               continue;
                
            }
            else
            {
                for(int j=i+1;j<=min(n-1,arr[i]+i);j++)
                {
                    if(jp[j]!=INT_MAX)
                    {
                        jp[i]=min(jp[i],1+jp[j]);
                    }
                }
            }
        }
        if(jp[0]==INT_MAX)
        return -1;
        return jp[0];
        
    }
};