class Solution {
public:
    string trimTrailingVowels(string s) 
    {
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                continue;
            }
            else
            return s.substr(0,i+1);
        }
        return "";
        
    }
};