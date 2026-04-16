class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) 
    {
        int n=arr.size();
        int mn=arr[n-1];
        int st=n;
        for(int i=n-2;i>=0;i--)
        {
            if(mn<arr[i])
            {
                st=i;
                break;
            }
            mn=min(mn,arr[i]);
        }
        if(st==n)
        return arr;
        mn=0;
        int swp=n;
        for(int j=n-1;j>st;j--)
        {
            if(arr[st]>arr[j] && mn<=arr[j])
            {
                swp=j;
                mn=arr[j];
            }
        }
        swap(arr[st],arr[swp]);
        return arr;
    }
};