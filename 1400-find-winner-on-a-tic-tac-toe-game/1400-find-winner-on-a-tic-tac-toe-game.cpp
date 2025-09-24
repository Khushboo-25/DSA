class Solution {
public:
    string tictactoe(vector<vector<int>>& mm) 
    {
         
         vector<vector<int>>m(3,vector<int>(3,0));
         int n=mm.size();
         for(int i=0;i<n;i++)
         {
            if(i%2==0)
            {
                m[mm[i][0]][mm[i][1]]=1;
            }
            else
            {
                m[mm[i][0]][mm[i][1]]=2;
            }
         }
        if(m[0][0]==m[0][1] && m[0][0]==m[0][2])
        {
            if(m[0][0]==1)
            {
                return "A";
            }
            else if(m[0][0]==2)
            return "B";
        }
        if(m[1][0]==m[1][1] && m[1][0]==m[1][2])
        {
            if(m[1][0]==1)
            {
                return "A";
            }
            else if(m[1][0]==2)
            return "B";
        }
        if(m[2][0]==m[2][1] && m[2][0]==m[2][2])
        {
            if(m[2][0]==1)
            {
                return "A";
            }
            else if(m[2][0]==2)
            return "B";
        }
        if(m[0][0]==m[1][0] && m[0][0]==m[2][0])
        {
            if(m[0][0]==1)
            {
                return "A";
            }
            else if(m[0][0]==2)
            return "B";
        }
        if(m[0][1]==m[1][1] && m[0][1]==m[2][1])
        {
            if(m[0][1]==1)
            {
                return "A";
            }
           else if(m[0][1]==2)
            return "B";
        }
        if(m[0][2]==m[1][2] && m[0][2]==m[2][2])
        {
            if(m[0][2]==1)
            {
                return "A";
            }
            else if(m[0][2]==2)
            return "B";
        }
        if(m[0][0]==m[1][1] && m[0][0]==m[2][2])
        {
            if(m[0][0]==1)
            {
                return "A";
            }
            else if(m[0][0]==2)
            return "B";
        }
        if(m[2][0]==m[1][1] && m[2][0]==m[0][2])
        {
            if(m[2][0]==1)
            {
                return "A";
            }
            else if(m[2][0]==2)
            return "B";
        }
        if(n==9)
        return "Draw";
        else
        return "Pending";
    }
};