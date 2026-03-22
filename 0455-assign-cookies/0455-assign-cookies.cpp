class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n=g.size();
        int m=s.size();
        int ans=0;
        int i=0,j=0;
        while(i<n)
        {
            while(j<m && g[i]>s[j])
            {
                j++;

            }
            if(j<m)
            {
                ans++;
                j++;
            }
            i++;
        }
        return ans;
        
    }
};