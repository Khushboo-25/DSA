class Solution {
public:
    int nextGreaterElement(int n) 
    {
        int t=n;
        
        string s=to_string(n);
        string ps=s;
        next_permutation(s.begin(),s.end());
        long long num=0;
        for(auto it:s)
        {
            num=num*1ll*10+(it-'0');
        }
        if(num<=n)
        return -1;
        if(num>INT_MAX*1ll)
        return -1;
        return num;
    }
};