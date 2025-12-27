class Solution {
public:
    int smallestIndex(vector<int>& nums)
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int d=nums[i];
            int s=0;
            while(d>0)
            {
                s+=d%10;
                d=d/10;
            }
            if(s==i)
            return i;
        }
        return -1;
        
    }
};