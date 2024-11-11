class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            int left=INT_MAX;
            int right=INT_MAX;
            if(i-1>=0)
            left=ratings[i-1];
            if(i+1<n)
            {
                right=ratings[i+1];
            }
            if(left>=ratings[i] && right>=ratings[i])
            {
                ans[i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==1)
            {
                int lf=i-1;
                while(lf>=0 && ratings[lf]>ratings[lf+1])
                {
                    ans[lf]=max(ans[lf],ans[lf+1]+1);
                    lf--;
                }
                int rf=i+1;
                while(rf<n && ratings[rf]>ratings[rf-1])
                {
                    ans[rf]=max(ans[rf],ans[rf-1]+1);
                    rf++;
                }
            }
        }
        int coins=0;
        for(auto it: ans)
        {
            
            coins+=abs(it);
        }
        return coins;
        
    }
};