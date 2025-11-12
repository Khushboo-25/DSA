class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        
        int n=nums.size();
        vector<int>a(n,0);

        int rr=-1,ms=-1;
        for(auto it:nums)
        {
            a[it-1]++;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                ms=i+1;
            }
            if(a[i]==2)
            rr=i+1;
        }
        return {rr,ms};

        
    }
};