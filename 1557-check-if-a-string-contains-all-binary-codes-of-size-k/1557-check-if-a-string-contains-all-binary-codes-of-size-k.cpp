class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // set<string> st;
        unordered_set<long long>pp;
        int n=s.size();
        if(n<k)
        return false;
        long long hash1=0;
        for(int i=0;i<k;i++)
        {
            hash1+=(s[i]-'0')*1ll*(1<<i);
        }
        if(s.size()>=k)
        pp.insert(hash1);
        for(int i=k;i<n;i++)
        {
            hash1=hash1/2+(s[i]-'0')*1ll*(1<<(k-1));
            pp.insert(hash1);
           
        }
        return pp.size()==(1<<k);
        
        
        
    }
};