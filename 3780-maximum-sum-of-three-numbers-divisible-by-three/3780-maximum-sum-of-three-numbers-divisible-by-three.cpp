class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        sort(nums.rbegin(),nums.rend());
        vector<int>a0,a1,a2;
        for(auto it:nums)
        {
            if(it%3==0)
            a0.push_back(it);
            else if(it%3==2)
            a2.push_back(it);
            else
            a1.push_back(it);
        }
        int ans=0;
        if(a0.size()>=3)
        ans=max(a0[0]+a0[1]+a0[2],ans);
        if(a0.size()>=1 && a1.size()>=1 && a2.size()>=1)
        ans=max(ans,a0[0]+a1[0]+a2[0]);
        if(a1.size()>=3)
        ans=max(a1[0]+a1[1]+a1[2],ans);
        if(a2.size()>=3)
        ans=max(a2[0]+a2[1]+a2[2],ans);
        return ans;
        // 0 0 0
        /*
        000
        012
        111
        222

        */
        
    }
};