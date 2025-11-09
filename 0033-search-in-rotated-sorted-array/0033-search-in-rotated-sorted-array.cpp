class Solution {
public:
    int search(vector<int>& nums, int tt) 
    {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(nums[m]==tt)
            return m;
            if(nums[s]<=nums[m])
            {
                if(nums[m]>=tt && nums[s]<=tt)
                {
                    e=m-1;
                }
                else
                {
                    s=m+1;
                }
            }
            else
            {
                if(nums[m]<=tt && nums[e]>=tt)
                {
                    s=m+1;
                }
                else
                {
                    e=m-1;
                }
            }
        }
        return -1;

        
    }
};