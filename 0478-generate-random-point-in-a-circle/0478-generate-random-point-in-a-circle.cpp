class Solution {
public:
    double r, xc, yc;

    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
    }
    
    vector<double> randPoint() {
        double u = (double)rand() / RAND_MAX;
        double v = (double)rand() / RAND_MAX;
        
        double rad = r * sqrt(u);
        double theta = 2 * M_PI * v;
        
        double x = xc + rad * cos(theta);
        double y = yc + rad * sin(theta);
        
        return {x, y};
    }
};