class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int x=0;
        for(auto it: nums)
        {
            x^=it;
        }
        x^=k;
        int ans=0;
        while(x>0)
        {
            ans+=x%2;
            x=x/2;
        }
        return ans;
        
    }
};