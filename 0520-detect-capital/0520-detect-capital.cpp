class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool st=0;
        if(word[0]>='A'&& word[0]<='Z')
        st=1;
        int n=word.size();
        int cp=0,sp=0;
        for(int i=1;i<n;i++)
        {
            if(word[i]>='A'&& word[i]<='Z')
            cp++;
            else
            sp++;
        }
        if(st) // capital
        {
            if(cp==n-1 || cp==0)
            return 1;
            return 0;
        }
        if(cp==0)
        return 1;
        return 0;
        
    }
};