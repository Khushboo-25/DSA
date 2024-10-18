class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        
        unordered_map<int,int>fr;
        for(auto it: deck)
        {
            fr[it]++;
        }
        vector<int>a;
        for(auto it:fr)
        {
            a.push_back(it.second);

        }
        
        int ans=a[0];
        for(int i=1;i<a.size();i++)
        {
            ans=__gcd(ans,a[i]);
        }
        if(ans!=1)
        return 1;
        return 0;
        
    }
};