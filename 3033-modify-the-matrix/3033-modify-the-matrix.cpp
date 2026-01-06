class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& mat) 
    {
        unordered_map<int,int>pp;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pp[j]=max(pp[j],mat[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==-1)
                mat[i][j]=pp[j];
            }
        }
        return mat;
        
    }
};