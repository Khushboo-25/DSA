class Solution {
public:
double call(vector<int>&p1,vector<int> &p2,vector<int> &p3)
{
    double ans=0;
    ans+=p1[0]*1.0*(p2[1]-p3[1]);
    ans+=p2[0]*1.0*(p3[1]-p1[1]);
    ans+=p3[0]*1.0*(p1[1]-p2[1]);
    ans=abs(ans)/2.0;
    return ans;
}
    double largestTriangleArea(vector<vector<int>>& p) 
    {
        double ans=0;
        int n=p.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    ans=max(ans,call(p[i],p[j],p[k]));
                }
            }
        }
        
        return ans;
    }
};