class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        int n=mat.size(),m=mat[0].size();
        unordered_map<int,int>cc,rr;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cc[j]+=mat[i][j];
                rr[i]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1 && rr[i]==1 && cc[j]==1)
                ans++;
            }
        }
        return ans;
        
    }
};