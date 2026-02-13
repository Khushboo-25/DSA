class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>ps;
        for(auto it:nums)
        {
            if(it>=0)
            ps.push_back(it);
        }
        if(ps.size()==0)
        return nums;
        k=k%(ps.size());
        reverse(ps.begin(),ps.end());
        reverse(ps.begin(),ps.begin()+(ps.size()-k));
        reverse(ps.begin()+(ps.size()-k),ps.end());
        // for(auto it:ps)
        // cout<<it<<" ";
        int i=0;
        for(auto &it: nums)
        {
            if(it>=0)
            {
                it=ps[i++];
            }
        }
        return nums;
        // 1 2 3 4 5 6
        // 3 4 5 6 1 2
        // 6 5 4 3 2 1
        
    }
};