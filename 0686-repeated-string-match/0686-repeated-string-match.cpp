class Solution {
public:

    int repeatedStringMatch(string a, string b) 
    {
        string s = a;
        int res = 1;
        int n = b.size()/a.size();
        for(int i=0;i<=n+1;i++){
            if(s.find(b) !=-1) 
            return res;
                s+=a;
                res++;
        }
        return -1;
    }
};