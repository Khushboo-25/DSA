class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_map<int,int>pp,pp1;
        for(auto it: p)
        {
            pp[it-'a']++;
        }
        int n1=s.size(),n2=p.size();
        if(n1<n2)
        return {};
        vector<int> ans;
        for(int i=0;i<n2;i++)
        {
            pp1[s[i]-'a']++;
        }
        if(pp==pp1)
        ans.push_back(0);
        for(int i=n2;i<=n1;i++)
        {
            if(i<n1)
            {
                pp1[s[i]-'a']++;
            }
            if(pp1[s[i-n2]-'a']>1)
            pp1[s[i-n2]-'a']--;
            else
            pp1.erase(s[i-n2]-'a');
            if(pp==pp1)
            ans.push_back(i-n2+1);
        }
        return ans;
        
    }
};