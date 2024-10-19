class Solution {
public:
    //total water is trapped into the bars
    int trap(vector<int>& h) 
    {
        int lf=0,rf=0;
        int n=h.size();
        int s=0,e=n-1;
        int ans=0;
        while(s<e)
        {
            lf=max(lf,h[s]);
            rf=max(rf,h[e]);
            if(lf<=rf) 
            {
                ans+=lf-h[s];
                s++;
            }
            else
            {
                ans+=rf-h[e];
                e--;
            }
        }
        return ans;
    }
};