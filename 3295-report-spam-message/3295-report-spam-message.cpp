class Solution {
public:
    bool reportSpam(vector<string>& ms, vector<string>& bn) 
    {
        unordered_map<string,bool>pp;
        for(auto it:bn)
        pp[it]=1;
        int ans=0;
        for(auto it:ms)
        {
            if(pp.find(it)!=pp.end())
            {
                ans++;
            }
            if(ans>=2)
            return 1;
        }
        return 0;
        
    }
};