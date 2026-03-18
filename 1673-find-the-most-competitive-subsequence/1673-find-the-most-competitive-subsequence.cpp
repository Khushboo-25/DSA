class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        int i=0;
        int n=nums.size();
        map<int,int>pp;
        for(int j=0;j<=n-k;j++)
        {
            pp[nums[j]]++;
        }
        vector<int>ans;

        for(int j=n-k;j<n;j++)
        {
            auto it=pp.begin();
            int x=it->first;
            ans.push_back(x);
            while(i<n && nums[i]!=x)
            {
                if(pp.find(x)!=pp.end())
                {
                    if(pp[nums[i]]==1)
                    {
                        pp.erase(nums[i]);
                    }
                    else
                    pp[nums[i]]--;
                    i++;
                }
                else
                break;
            }
            if(pp.find(x)!=pp.end())
                {
                    if(pp[x]==1)
                    pp.erase(x);
                    else
                    pp[x]--;
                    
                    i++;
                }
                
            if(j+1<n)
            pp[nums[j+1]]++;
        }
        
        return ans;
    }
};