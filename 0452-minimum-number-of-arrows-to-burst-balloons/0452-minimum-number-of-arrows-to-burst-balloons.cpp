class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp=[](auto a,auto b) {
            return a[1]<b[1];
        };
        sort(points.begin(),points.end(),cmp);
    //     for(auto it: points)
    //    {
    //     cout<<"(";
    //     for(auto it1:it)
    //     cout<<it1<< " ";
    //     cout<<")";
    //     cout<<endl;
    //    } 
        int n=points.size(),count=1,prev=points[0][1];
        for(int i=1;i<n;i++) {
            if(points[i][0]<=prev) {
                continue;
            }
            else {
                count++;
                prev=points[i][1];
            }
        }
        return count;
    }
};