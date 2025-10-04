class Solution {
public:
    int numberOfBeams(vector<string>& bk) 
    {
        int cn1=0;
        int ans=0;
        for(auto it:bk)
        {
            int c0=0;
            for(auto it1:it)
            {
                if(it1=='1')
                c0++;
            }
            if(c0!=0)
            {
                ans+=c0*cn1;
                cn1=c0;
            }
        }
        return ans;
    }
};