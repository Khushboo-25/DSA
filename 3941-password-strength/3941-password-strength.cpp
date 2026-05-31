class Solution {
public:
    int passwordStrength(string password) 
    {
        unordered_map<char,bool>pp;
        for(auto it:password)
        {
            pp[it]=1;
        }
        int ans=0;
        for(auto it:pp)
        {
            cout<<it.first<<" ";
            if(it.first<='z' && it.first>='a')
            ans++;
            else if(it.first<='Z' && it.first>='A')
            ans+=2;
            else if(it.first<='9' && it.first>='0')
            ans+=3;
            else
            ans+=5;
        }
        return ans;
        
    }
};