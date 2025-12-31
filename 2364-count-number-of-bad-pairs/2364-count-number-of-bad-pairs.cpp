class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        int n=nums.size();
        long long ans=0;
        unordered_map<int,int>pp;
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]-i;
            pp[nums[i]]++;
        }
        int s1=0;
        for(auto it:pp)
        {
            s1+=it.second;
            ans+=it.second*(n-s1);
        }
        return ans;
    }
};