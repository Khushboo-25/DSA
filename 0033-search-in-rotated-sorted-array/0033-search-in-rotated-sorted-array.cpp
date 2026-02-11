class Solution {
public:
    int search(vector<int>& nums, int x) 
    {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(nums[m]==x)
            return m;
            if(nums[s]<=nums[m] && nums[e]<=nums[m])
            {
                if(nums[m]>=x && nums[s]<=x)
                {
                    e=m-1;
                }
                else
                s=m+1;
            }
            else if(nums[m]<=nums[s] && nums[m]<=nums[e])
            {
                if(nums[m]<=x && nums[e]>=x)
                {
                    s=m+1;
                }
                else
                e=m-1;
            }
            else
            {
                if(nums[m]>=x)
                {
                    e=m-1;
                }
                else
                s=m+1;
            }
        }
        return -1;
    }
};