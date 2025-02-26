class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        
        int s=0,s1=0;
        int mxp=0,mxn=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            
                s=max(nums[i],s+nums[i]);
                mxp=max(s,mxp);
                s1=min(nums[i],s1+nums[i]);
                mxn=min(s1,mxn);
            
            

        }
        // cout<<mxn<<" "<<mxp<<endl;
        return max(abs(mxn),abs(mxp));
        
    }
};