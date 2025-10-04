class SubrectangleQueries {
public:
    vector<vector<int>> mat;

    SubrectangleQueries(vector<vector<int>>& rt) {
        mat = rt;  
    }
    
    void updateSubrectangle(int r1, int c1, int r2, int c2, int nv) {
        for(int i = r1; i <= r2; i++) {
            for(int j = c1; j <= c2; j++) {
                mat[i][j] = nv;
            }
        }
    }
    
    int getValue(int row, int col) {
        return mat[row][col];
    }
};
