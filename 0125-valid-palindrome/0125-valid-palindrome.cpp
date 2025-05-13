class Solution {
public:
 bool nonchar(char it)
 {
    if(it<='Z'&& it>='A')
    return 0;
    if(it<='z' && it>='a')
    return 0;
    if(it<='9' && it>='0')
    return 0;
    return 1;

 }
    bool isPalindrome(string st) 
    {
        queue<char> s1;
        stack<char> s2;
        for(auto it: st)
        {
            if(nonchar(it))
            continue;
            else if(it<='Z'&& it>='A')
            {
                char u='a'+it-'A';
                s1.push(u);
                s2.push(u);
            }
            else
            {
                s1.push(it);
                s2.push(it);
            }
        }
        if(s1.size()!=s2.size())
        return 0;
        while(!s1.empty())
        {
            
            if(s1.front()!=s2.top())
            return 0;
            s1.pop();
            s2.pop();

        }
        
        return 1;


        
    }
};