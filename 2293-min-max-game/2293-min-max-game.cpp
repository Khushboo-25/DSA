class Solution {
public:
    int minMaxGame(vector<int>& nums) 
    {
        while(nums.size()>1)
        {
            int i=0;
            vector<int>nw;
            bool pn=1;
            while(i<nums.size())
            {
                if(i%4==0)
                {
                    nw.push_back(min(nums[i],nums[i+1]));
                    
                }
                else
                {
                    nw.push_back(max(nums[i],nums[i+1]));
                    
                }
                i+=2;
            }
            nums=nw;
        }
        return nums[0];
        
    }
};