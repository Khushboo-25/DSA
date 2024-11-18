class Solution {
public:

    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int sn=0;
        unordered_map<int,int>pp;
        pp[sn]++;
        int n=nums.size();
        int cn=0;
        for(int i=n-1;i>=0;i--)
        {
            sn=(sn+nums[i])%k;
            if(sn<0)
            sn+=k;
            cn+=pp[sn];
            pp[sn]++;
            // if(pp[sn]>0)
            
            
        }
        return cn;
        
    }
};