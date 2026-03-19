class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string,int>pp;
        
        int ans=0;
        for(auto it:words)
        {
            string s=it;
            reverse(s.begin(),s.end());
            if(pp.find(s)!=pp.end())
            {
                ans+=4;
                
                if(pp[s]==1)
                pp.erase(s);
                else
                pp[s]--;
            }
            else
            pp[it]++;
        }
        int ans1=0;
        for(auto it:pp)
        {
            string s=it.first;
            reverse(s.begin(),s.end());
            if(s==it.first  && it.second>0)
            {
                ans1+=2;
                break;
            }
        }
        return ans+ans1;
        
    }
};