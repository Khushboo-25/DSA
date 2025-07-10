class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char> ct;
        for(auto it:s)
        {
            if(!ct.empty() && ct.top()=='(' && it==')')
            ct.pop();
            else
            ct.push(it);
        }
        return ct.size();
        
    }
};