class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        vector<int>first(26,-1);
        vector<int>last(26,n);
        for(int i=0;i<n;i++)
        {
            int c=s[i]-'a';
            if(first[c]==-1)
            first[c]=i;
            last[c]=i;
        }
        int ans=-1;
        for(int i=0;i<26;i++)
        {
            if(first[i]!=-1)
            {
                ans=max(ans,last[i]-first[i]-1);
            }
        }
        return ans;

    }
};