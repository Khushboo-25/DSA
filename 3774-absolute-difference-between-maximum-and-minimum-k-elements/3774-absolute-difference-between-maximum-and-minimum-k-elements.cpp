class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s1=0,s2=0;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            s1+=nums[i];
            s2+=nums[n-1-i];
        }
        return abs(s1-s2);
    }
};