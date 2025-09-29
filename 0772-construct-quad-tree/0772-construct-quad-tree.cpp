class Solution {
public:
    Node* call(int x1,int y1,int x2,int y2,vector<vector<int>>& grid)
    {
        if(x1==x2 && y1==y2) // single cell
            return new Node(grid[x1][y1], true);

        int mx = x1 + (x2 - x1) / 2;
        int my = y1 + (y2 - y1) / 2;

        Node* topLeft = call(x1, y1, mx, my, grid);
        Node* topRight = call(x1, my+1, mx, y2, grid);
        Node* bottomLeft = call(mx+1, y1, x2, my, grid);
        Node* bottomRight = call(mx+1, my+1, x2, y2, grid);

        // Merge if all four children are leaves and have same value
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val) {
            bool v = topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return new Node(v, true);
        }

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) 
    {
        return call(0, 0, grid.size()-1, grid.size()-1, grid);
    }
};
