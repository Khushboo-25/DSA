class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        int ans=INT_MAX;
        unordered_map<char,int>pp;
        for(auto it:text)
        pp[it]++;
        
        ans=min(ans,pp['b']);
        ans=min(ans,pp['a']);
        ans=min(ans,pp['l']/2);
        ans=min(ans,pp['o']/2);
        ans=min(ans,pp['n']);
        return ans;
    }
};