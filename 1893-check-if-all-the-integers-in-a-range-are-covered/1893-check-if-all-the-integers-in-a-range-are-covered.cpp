class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) 
    {
        vector<bool> av(51,0);
        for(auto it:ranges)
        {
            int x=it[0],y=it[1];
            for(int i=x;i<=y;i++)
            av[i]=1;
        }
        for(int i=left;i<=right;i++)
        {
            if(av[i]==false)
            return 0;
        }
        return 1;
        
    }
};