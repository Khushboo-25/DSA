class Solution {
public:
    int residuePrefixes(string s)
    {
        int n=s.size();
        unordered_set<char>st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
            if(st.size()==(i+1)%3)
            ans++;
        }
        return ans;
    }
};