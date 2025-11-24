class Solution {
public:
bool call(int sz,vector<int>&nums,int &lm,int &n)
{
    multiset<int>st;
    for(int i=0;i<sz;i++)
    st.insert(nums[i]);
    int mn=*st.begin();
    int mx=*st.rbegin();
    if(lm>=mx-mn)
    return 1;
    for(int i=sz;i<n;i++)
    {
        auto it=st.find(nums[i-sz]);
        st.erase(it);
        st.insert(nums[i]);
        int mn1=*st.begin();

        int mx1=*st.rbegin();
        if(lm>=mx1-mn1)
        return 1;
    }
    return 0;
}
    int longestSubarray(vector<int>& nums,int &lm) 
    {
        int ans=1;
        int n=nums.size();
        int s=1,e=n;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(call(m,nums,lm,n))
            {
                ans=m;
                s=m+1;
            }
            else
            e=m-1;
        }
        return ans;
    }
};