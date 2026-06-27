class Solution {
public:
    bool canChange(string SS, string TT) {


        vector<int>s,t;
        int n=SS.size();
        for(int i=0;i<n;i++)
        {
            if(SS[i]!='_')
            s.push_back(i);
        }
        for(int j=0;j<n;j++)
        {
            if(TT[j]!='_')
            t.push_back(j);
        }
        if(s.size()!=t.size())
        return 0;
        int m=s.size();
        for(int i=0;i<m;i++)
        {
            
            if(SS[s[i]]!=TT[t[i]])
            return 0;
            else if(SS[s[i]]=='L' && s[i]<t[i])
            return 0;
            else if(SS[s[i]]=='R' && s[i]>t[i])
            return 0;
        }
        return 1;
        
    }
};