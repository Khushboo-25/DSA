class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int s=0,e=0;
        int n=mat.size();
        int m=mat[0].size();
        int d=1;
        vector<int> ans;
        while(ans.size()<n*m)
        {
            ans.push_back(mat[s][e]);
            if(d==1) // up...
            {
                while(s-1>=0  && e+1<m)
                {
                    s--;
                    e++;
                    ans.push_back(mat[s][e]);
                }
                if(e+1<m)
                {
                    e++;
                }
                else
                {
                    s++;
                }
                d=-1;
            }
            else
            {
                while(s+1<n && e-1>=0)
                {
                    s++;
                    e--;
                    ans.push_back(mat[s][e]);
                }
                if(s+1<n)
                {
                    s++;
                }
                else
                {
                    e++;
                }
                d=1;
            }
        }
        return ans;

        
    }
};