class Solution {
public:
    int numberOfSpecialChars(string s) 
    {
        vector<int>low(26,-1);
        vector<int>up(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                int cn=s[i]-'a';
                low[cn]=max(low[cn],i);
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                int cn=s[i]-'A';
                if(up[cn]==-1)
                up[cn]=i;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            // cout<<low[i]<<" "<<up[i]<<endl;
            if(low[i]!=-1 && up[i]!=-1 && low[i]<up[i])
            ans++;
        }
        return ans;
        
    }
};