class Solution {
public:
    int firstMatchingIndex(string st) 
    {
        int n=st.size();
        int s=0,e=n-1;
        while(s<=e)
        {
            if(st[s]==st[e])
            return s;
            s++;
            e--;
        }
        return -1;

        
    }
};