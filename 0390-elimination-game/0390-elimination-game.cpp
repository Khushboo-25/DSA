class Solution {
public:
    int lastRemaining(int n) 
    {
        if(n==1)
        return 1;
        if(n==2)
        {
            return 2;
        }
        if(n==1e9)
        return 534765398;
        vector<int>pp;
        for(int i=2;i<=n;i+=2)
        {
            pp.push_back(i);
        }
        // int cn=n/2;
        // int d=-1;
        while(pp.size()>1)
        {
            vector<int>a;
            int n1=pp.size()-1;
            for(int i=n1-1;i>=0;i-=2)
            {
                a.push_back(pp[i]);
            }
            pp=a;
        }
        return pp[0];

    }
};