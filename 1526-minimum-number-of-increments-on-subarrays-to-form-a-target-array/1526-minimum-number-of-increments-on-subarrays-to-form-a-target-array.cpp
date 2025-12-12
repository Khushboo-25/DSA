class Solution {
public:
    int minNumberOperations(vector<int>&tr)
    {
        int ans=0;
        int pr=0;
        for(auto it:tr)
        {
            if(it>=pr)
            {
                ans+=it-pr;
                pr=it;
            }
            else
            {
                pr=it;
            }
        }
        return ans;
    }
};