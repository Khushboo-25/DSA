class Solution {
public:
    int waysToMakeFair(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>as(n,0);
        vector<int>bs(n,0);
        for(int i=0;i<n;i++)
        {
            as[i]=nums[i];
            if(i-2>=0)
            {
                as[i]+=as[i-2];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            bs[i]=nums[i];
            if(i+2<n)
            {
                bs[i]+=bs[i+2];
            }
        }
        int ans=0;
            for(int i=0;i<n;i++)
            {
                int odd=0;
                int ev=0;   
                if(i%2==0)
                {
                    if(i-1>=0) //odd
                    odd+=as[i-1];
                    if(i-2>=0) //even
                    ev+=as[i-2];
                    if(i+1<n) // even
                    ev+=bs[i+1];
                    if(i+2<n) //odd
                    odd+=bs[i+2];
                }
                else
                {
                    if(i-1>=0) //even
                    ev+=as[i-1];
                    if(i-2>=0) //odd
                    odd+=as[i-2];
                    if(i+1<n) //odd
                    odd+=bs[i+1];
                    if(i+2<n) //even
                    ev+=bs[i+2];
                }   
                if(odd==ev)
                ans++;
            }
            return ans;
    }
};