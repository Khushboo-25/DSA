class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int ans=0;
        int l=0;
        int cn=0,cp=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)// 0
            {
                cn=0,cp=0;
                
            }
            else if(nums[i]>0)//+ve
            {
                cp++;
            }
            else//-ve
            {
                cn++;
            }
            if(cn%2==0)
            {
                ans=max(cn+cp,ans);
            }
        }
        cn=0,cp=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==0)// 0
            {
                cn=0,cp=0;
            }
            else if(nums[i]>0)//+ve
            {
                cp++;
            }
            else//-ve
            {
                cn++;
            }
            if(cn%2==0)
            {
                ans=max(cn+cp,ans);
            }
        }
        return ans;
    }
};