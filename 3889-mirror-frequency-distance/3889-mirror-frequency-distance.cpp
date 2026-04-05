class Solution {
public:
    int mirrorFrequency(string s) 
    {
        unordered_map<char,int>pp;
        for(auto it:s)
        {
            pp[it]++;
        }  
        int ans=0;

        for(char c='a';c<='m';c++)
        {
            char c1='z';
            int mv=c-'a';
            c1-=mv;
            ans+=abs(pp[c]-pp[c1]);
            // cout<<c1<<" ";
        }
        for(char c='0';c<='4';c++)
        {
            char c1='9';
            int mv=c-'0';
            c1-=mv;
            ans+=abs(pp[c]-pp[c1]);
            // cout<<c1<<" ";
        }
        return ans;
        // abcdefghijklm
        // nopqrstuvwxyz      
    }
};