class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>a(n+2,1),b(n+2,1);
        a[1]=nums[0];
        b[n]=nums[n-1];
        for(int i=2;i<=n;i++) 
        {
            a[i]=a[i-1]*nums[i-1];
            // cout<<a[i]<<" ";
        }

        for(int i=n-1;i>=1;i--)
        {
            b[i]=nums[i-1]*b[i+1];
            // cout<<b[i]<<" ";
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=a[i]*b[i+2];
        }
        return nums;
        
    }
};