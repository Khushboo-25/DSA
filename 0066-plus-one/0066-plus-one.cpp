class Solution {
public:
    vector<int> plusOne(vector<int>& dg) 
    {
        reverse(dg.begin(),dg.end());
        int n=dg.size();
        int c=1;

        for(int i=0;i<n;i++)
        {
            int nc=(dg[i]+c)/10;
            dg[i]=(dg[i]+c)%10;
            c=nc;
        }
        if(c!=0)
        dg.push_back(c);
        reverse(dg.begin(),dg.end());
        return dg;
    }
};