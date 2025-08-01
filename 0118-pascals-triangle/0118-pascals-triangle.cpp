class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> v(1,vector<int>(1,1));

        if(n==1)
        return v;
        for(int i=1;i<n;i++)
        {
            vector<int>vv(i+1,1);
            for(int j=1;j<i;j++)
            {
                vv[j]=v[i-1][j]+v[i-1][j-1];
            }
            v.push_back(vv);

        }
        return v;

        
    }
};