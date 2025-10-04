class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& pn, vector<vector<int>>& qr) 
    {
        int n=qr.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int cx=qr[i][0];
            int cy=qr[i][1];
            int cr=qr[i][2];
            for(auto p:pn)
            {
                int x=p[0];
                int y=p[1];
                int d=(x-cx)*(x-cx)+(y-cy)*(y-cy);
                if(cr*cr>=d)
                {
                    ans[i]++;
                }
            }
        }
        return ans;
        
    }
};