class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(),costs.end());
        int s=0;
        int ans=0;
        for(auto it:costs)
        {
            if(s+it>coins)
            return ans;
            s+=it;
            ans++;
        }
        return ans;
        
    }
};