class Solution {
public:
bool call(string &s1,string &s2)
{
    string sw=s1+"&"+s2;
    int n=s1.size();
    for(int i=n+1;i<sw.size();i++)
    {
        int j=0;
        int k=i;
        while(j<sw.size())
        {
            if(sw[k]==sw[j])
            {
                k++;
                j++;
            }
            else
            break;
            if(j>=s1.size())
            return 1;
        }
    }
    return 0;

}
    vector<string> stringMatching(vector<string>& words)
    {
        vector<string>ans;
        int n=words.size();
        sort(words.begin(),words.end());
        for(int i=0;i<n;i++)
        {
            // cout<<words[i]<<" ";
            for(int j=0;j<n;j++)
            {
                if(i!=j && call(words[i],words[j]))
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};