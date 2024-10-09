class Solution {
public:
void update(string &word,int s,int e)
{
    while(s<e)
    {
        swap(word[s],word[e]);
        s++;
        e--;
    }
}
    string reversePrefix(string word, char ch) 
    {
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(word[i]==ch)
            {
                update(word,0,i);

                break;
            }
        }
        return word;
    }
};