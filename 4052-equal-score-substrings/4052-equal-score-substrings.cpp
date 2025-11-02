class Solution {
public:
    bool scoreBalance(string s) 
    {
        unordered_map<int,int>pp;
        int sm=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            sm+=(s[i]-'a')+1;
            // cout<<sm<<" ";
            pp[sm]++;
        }
        if(sm%2==0 && pp[sm/2]>=1)
        return 1;
        return 0;
        
    }
};