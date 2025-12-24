class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans(n,0);
        unordered_map<int,int>pp;
        for(int i=n-1;i>=0;i--)
        {
            pp[nums[i]]++;
            ans[i]=pp.size();
        }
        int c=0;
        for(int i=0;i<n;i+=3)
        {
            if(ans[i]==n-i)
            {
                return c;
            }
            c++;
        }
        return c;
        
    }
};