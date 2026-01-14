class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int ans=0;
        int m=pref.size();
        for(auto it:words)
        {
            if(it.size()>=m && it.substr(0,m)==pref)
            ans++;
        }
        return ans;
        
    }
};