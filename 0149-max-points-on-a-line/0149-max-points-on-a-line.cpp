class Solution {
public:
bool check(int &x1,int &y1,int &x2,int &y2,int &x,int &y)
{
    long long int a1=(x-x1)*1ll*(y2-y1);
    long long int b1=(y-y1)*1ll*(x2-x1);
    return (a1==b1);
}
    int maxPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        if(n<=2)
        return n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cn=0;
                for(int k=0;k<n;k++)
                {
                    
                    if(k!=i && k!=j && i!=j )
                    {
                        int x1=points[i][0];
                        int y1=points[i][1];
                        int x2=points[j][0];
                        int y2=points[j][1];
                        int x=points[k][0];
                        int y=points[k][1];
                        if(check(x1,y1,x2,y2,x,y))
                        {
                            cn++;
                        } 
                        
                    }
                    
                }
                ans=max(ans,cn+2);
            }
        }
        return ans;
        
    }
};