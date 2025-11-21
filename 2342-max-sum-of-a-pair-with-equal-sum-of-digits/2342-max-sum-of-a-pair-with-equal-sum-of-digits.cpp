class Solution {
public:
int call(int num)
{
    int ans=0;
    while(num)
    {
        ans+=num%10;
        num/=10;
    }
    return ans;
}
    int maximumSum(vector<int>& nums) 
    {
        unordered_map<int,int>pp;
        int ans=0;
        for(auto it: nums)
        {
            int ds=call(it);
            if(pp.find(ds)!=pp.end())
            {
                ans=max(ans,pp[ds]+it);
            }
            pp[ds]=max(pp[ds],it);
        }
        if(ans==0)
        return -1;
        return ans;
    }
};