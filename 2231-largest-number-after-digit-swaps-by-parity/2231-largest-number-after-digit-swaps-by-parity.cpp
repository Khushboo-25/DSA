class Solution {
public:
    int largestInteger(int num) 
    {
        string s=to_string(num);
        string ev="",od="";
        for(auto it:s)
        {
            if((it-'0')%2==0)
            ev+=it;
            else
            od+=it;
        }
        sort(ev.rbegin(),ev.rend());
        sort(od.rbegin(),od.rend());
        int i=0,j=0;
        string s2="";
        for(auto it:s)
        {
            if((it-'0')%2==0)
            {
                s2+=ev[i++];
            }
            else
            s2+=od[j++];
        }
        int n2=0;
        for(auto it:s2)
        {
            int d=it-'0';
            n2=n2*10+d;
        }
        return n2;
    }
};