class Solution {
public:
void update(unordered_map<string,int> &pp,string &word)
{
    int num=0;
    int n1=word.size();
    for(int i=0;i<n1;i++)
    {
        int lc=word[i]-'a';
        num=num|(1<<lc);
    }
    pp[word]=num;
}
bool check(int f1,int f2)
{
    
    return ((f1&f2)==0);

}
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();
        unordered_map<string,int>pp;

        for(int i=0;i<n;i++)
        {
            update(pp,words[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int f1=pp[words[i]];
                int f2=pp[words[j]];
                if(check(f1,f2))
                {
                    int l1=words[i].size()*words[j].size();
                    ans=max(ans,l1);
                    // ans=max(words[i].size()*words[j].size(),ans);
                }

            }

        }
        return ans;

        
    }
};