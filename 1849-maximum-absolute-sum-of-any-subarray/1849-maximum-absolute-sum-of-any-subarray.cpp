class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int mxp=0;
        int s=0,s1=0;
        int mxn=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(s+nums[i]<=nums[i])
            {
                s=max(s,nums[i]);
            }
            else
            {
                s+=nums[i];
            }
            mxp=max(mxp,s);
            
            if(s1+nums[i]>=nums[i])
            {
                s1=min(s1,nums[i]);
            }
            else
            {
                s1+=nums[i];
            }
            mxn=min(mxn,s1);

        }
        cout<<mxn<<" "<<mxp<<endl;
        return max(abs(mxp),abs(mxn));
        
    }
};