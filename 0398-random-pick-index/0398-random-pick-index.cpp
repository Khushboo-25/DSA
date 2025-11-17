class Solution {
public:
vector<int>st;

    Solution(vector<int>& nums) {
        for(auto it:nums)
        {
            st.push_back(it);
        }
    }
    
    int pick(int target) {
        vector<int>av;
        
        int n=st.size();
        for(int i=0;i<n;i++)
        {
            if(st[i]==target)
            av.push_back(i);
        }
        int rn=rand()%(av.size());
        return av[rn];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */