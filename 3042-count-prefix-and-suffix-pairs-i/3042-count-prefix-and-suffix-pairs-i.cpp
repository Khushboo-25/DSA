class Solution {
public:
bool call(string &s1,string &s2)
{
    int n=s1.size();
    int m=s2.size();
    if(n>m)
    return 0;
    if(s2.substr(0,n)!=s1 || s2.substr(m-n,n)!=s1)
    return 0;
    return 1;
}
    int countPrefixSuffixPairs(vector<string>& words)
    {
        int ans=0;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(call(words[i],words[j]))
                ans++;
            }
        }
        return ans;        
    }
};