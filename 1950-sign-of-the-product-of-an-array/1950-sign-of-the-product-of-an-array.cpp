class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int nn=0;
        for(auto it:nums)
        {
            if(it==0)
            return 0;
            else if(it<0)
            {
                nn++;
                nn=nn%2;
            }
        }
        if(nn==0)
        return 1;
        return -1;
        
    }
};