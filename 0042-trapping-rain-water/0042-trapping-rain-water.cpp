class Solution {
public:
    int trap(vector<int>& h) 
    {
        int n=h.size();
        int s=0,e=n-1;
        int lv=0;
        int ans=0;
        while(s<=e)
        {
            if(h[s]<h[e]) // mnh lv 
            {
                if(lv>=h[s])
                ans+=lv-h[s];
                lv=max(lv,h[s]);
                s++;
            }
            else
            {
                if(lv>=h[e])
                ans+=lv-h[e];
                lv=max(lv,h[e]);
                e--;
            }
        }
        return ans;
    }
};