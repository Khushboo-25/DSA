class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        for(int i=n-2;i>0;i--)
        {
            int s=0,e=i;
            vector<int>st;
            while(s<n && e<n)
            {
                st.push_back(grid[s][e]);
                s++;e++;
            }
            sort(st.begin(),st.end());
            int j=0;
            s=0,e=i;
            while(s<n && e<n)
            {
                grid[s][e]=st[j];
                s++;e++;
                j++;
            }

        }
        for(int i=0;i<n;i++)
        {
            int s=i,e=0;
            vector<int>st;
            while(s<n && e<n)
            {
                st.push_back(grid[s][e]);
                s++;e++;
            }
            sort(st.rbegin(),st.rend());
            int j=0;
            s=i,e=0;
            while(s<n && e<n)
            {
                grid[s][e]=st[j];
                s++;
                e++;
                j++;
            }
        }
        return grid;
        
    }
};