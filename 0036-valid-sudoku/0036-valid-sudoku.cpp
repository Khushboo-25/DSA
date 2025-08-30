class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++)
        {
            unordered_map<int,int>pp;
            for(int j=0;j<9;j++)
            {
                if(b[i][j]!='.')
                {
                    if(pp[b[i][j]]>0)
                    return false;
                    pp[b[i][j]]++;
                }
            }
        }
        for(int i=0;i<9;i++)
        {
            unordered_map<int,int>pp;
            for(int j=0;j<9;j++)
            {
                if(b[j][i]!='.')
                {
                    if(pp[b[j][i]]>0)
                    return false;
                    pp[b[j][i]]++;
                }
            }
        }
        for(int i=0;i<9;i+=3)
        {
            
            for(int j=0;j<9;j+=3)
            {
                unordered_map<int,int> pp;
                for(int s=i;s<i+3;s++)
                {
                    for(int e=j;e<j+3;e++)
                    {
                        if(b[s][e]!='.')
                        {
                            if(pp[b[s][e]]>0)
                            {
                                return false;
                            }
                            pp[b[s][e]]++;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};