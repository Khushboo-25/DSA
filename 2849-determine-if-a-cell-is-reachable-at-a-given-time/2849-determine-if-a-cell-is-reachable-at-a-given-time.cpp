class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        int dist = max(abs(sx - fx), abs(sy - fy));

        // Special case: same start and finish
        if(sx == fx && sy == fy)
            return t != 1;  // if t == 1 → can't move and stay

        return dist <= t;
    }
};
