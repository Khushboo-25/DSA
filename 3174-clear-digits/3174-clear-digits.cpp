class Solution {
public:
    string clearDigits(string s) 
    {
        string ans="";
        for(auto it:s )
        {
            if(it<='z' && it>='a')
            {
                ans+=it;
            }
            else if(!ans.empty() && ans.back()<='z' &&ans.back()>='a')
            {
                ans.pop_back();
            }
            else
            ans+=it;
        }
        return ans;

        
    }
};