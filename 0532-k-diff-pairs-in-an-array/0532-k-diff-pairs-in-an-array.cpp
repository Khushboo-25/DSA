class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<string,bool>pp;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]-nums[i]==k)
                {
                    string s=to_string(nums[j])+','+to_string(nums[i]);
                    pp[s]=1;
                }
            }
        }
        return pp.size();
        
    }
};