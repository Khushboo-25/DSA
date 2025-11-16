class Solution {
public:
    int timeRequiredToBuy(vector<int>& tk, int k) 
    {
        queue<pair<int,int>>qt;
        int n=tk.size();
        for(int i=0;i<n;i++)
        {
            qt.push({i,tk[i]});
        }
        int tm=1;
        while(!qt.empty())
        {
            int in=qt.front().first;
            int vl=qt.front().second;
            qt.pop();
            if(vl>1)
            {
                qt.push({in,vl-1});
            }
            else
            {
                if(in==k)
                {
                    return  tm;
                }
            }
            tm++;
        }
        return 0;
        
    }
};