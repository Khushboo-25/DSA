class Solution {
public:
    long long maxStrength(vector<int>& nums) 
    {
        vector<int>pv,nv;
        for(auto it:nums)
        {
            if(it>0)
            pv.push_back(it);
            else if(it<0)
            nv.push_back(it);
        }
        sort(pv.begin(),pv.end());
        sort(nv.begin(),nv.end());
        long long ps=1;
        for(auto it:pv)
        ps=1ll*ps*it;
        long long ns=1;
        for(int i=0;i<nv.size()-(nv.size())%2;i++)
        ns=1ll*ns*nv[i];
        if(pv.empty() && nv.empty())
        return 0;
        if(pv.empty())
        {
            if(nv.size()==1)
            {
                if(nums.size()>1)
                return 0;
                return 1ll*nv[0];
            }
            return ns;
        }
        if(nv.empty())
        return ps;
        return 1ll*ps*ns;
    }
};