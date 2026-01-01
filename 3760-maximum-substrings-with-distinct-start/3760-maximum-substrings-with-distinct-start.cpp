class Solution {
public:
    int maxDistinct(string s) 
    {
        unordered_map<char,bool>pp;
        for(auto it:s)
        pp[it]=1;
        return pp.size();
        
    }
};