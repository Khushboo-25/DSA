class Solution {
public:
    int trap(vector<int>& ht) 
    {
        int n=ht.size();
        int lv=0;
        int s=0,e=n-1;
        int ans=0;
        while(s<=e)
        {
            if(ht[s]<=ht[e])
            {
                lv=max(lv,ht[s]);
                ans+=max(0,lv-ht[s]);
                s++;
            }
            else
            {
                lv=max(lv,ht[e]);
                ans+=max(0,lv-ht[e]);
                e--;
            }
        }
        return ans;
        
    }
};