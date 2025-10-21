class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) 
    {
        set<int>st;
        for(auto it:nums)
        {
            if(it%k==0)
            {
                st.insert(it/k);
            }
        }
        int f=1;
        for(auto it:st)
        {
            if(it!=f)
            return f*k;
            f++;
        }
        return f*k;
    }
};