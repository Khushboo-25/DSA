class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int n1=nums[i];
                int n2=nums[j];
                int d2=n1+n2-1;
                int d1=n2-n1-1;
                int cn2=upper_bound(nums.begin()+j+1,nums.end(),d2)-(nums.begin()+(j+1));
                int cn1=lower_bound(nums.begin()+j+1,nums.end(),d1)-(nums.begin()+(j+1));
                ans+=cn2-cn1;
                // n1<=n2 n2<=n3
                // n1+n2>n3 n1+n3>n2 n2+n3>n1
                // n3<=n1+n2-1;
                // n3>=n2-n1-1;
                // n3>=n1-n2-1;
                // n3>=
            }
        }
        return ans;
        
    }
};