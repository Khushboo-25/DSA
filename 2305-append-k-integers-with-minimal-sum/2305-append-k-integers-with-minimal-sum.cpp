class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) 
    {
        long long ans=0;
        
        set<int>a;
        for(auto it:nums)
        a.insert(it);
        nums.clear();
        for(auto it:a)
        {
            nums.push_back(it);
        }
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(k+i<nums[i])
            {
                long long ans1=((k+i)*1ll*(k+i+1))/2;
                return ans1-ans;
            }
            ans+=nums[i];
        }
        long long ans1=((k+n)*1ll*(k+n+1))/2;
        return  ans1-ans;

        
    }
};