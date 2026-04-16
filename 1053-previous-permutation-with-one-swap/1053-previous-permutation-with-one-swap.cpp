class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) 
    {
        int n=arr.size();
        vector<bool>can_swap(n,0);
        int mn=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(mn<arr[i])
            {
                can_swap[i]=1;
            }
            mn=min(mn,arr[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            if(can_swap[i])
            {
                int mn=0;

                int swp=n;
                for(int j=n-1;j>i;j--)
                {
                    if(arr[i]>arr[j] && mn<=arr[j])
                    {
                        swp=j;
                        mn=arr[j];
                    }
                }
                swap(arr[i],arr[swp]);
                return arr;
            }

        }
        return arr;
    }
};