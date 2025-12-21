class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<m;i++)
        {
            int s=0,e=i;
            while(s+1<n && e+1<m)
            {
                if(mat[s][e]!=mat[s+1][e+1])
                return 0;
                s++;
                e++;
            }
        }
        for(int i=1;i<n;i++)
        {
            int s=i,e=0;
            while(s+1<n && e+1<m)
            {
                if(mat[s][e]!=mat[s+1][e+1])
                return 0;
                s++;
                e++;
            }
        }
        return 1;
        
    }
};