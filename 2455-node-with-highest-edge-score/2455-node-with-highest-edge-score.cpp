class Solution {
public:
    int edgeScore(vector<int>& ed) 
    {
        int n=ed.size();
        vector<long long>out(n,0);
        for(int i=0;i<n;i++)
        {
            int m=ed[i];
            out[m]+=i*1ll;
        }
        long long mx=*max_element(out.begin(),out.end());
        for(int i=0;i<n;i++)
        {
            if(out[i]==mx)
            return i;
        }
        return -1;
        
    }
};