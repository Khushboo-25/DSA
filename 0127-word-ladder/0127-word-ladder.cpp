class Solution {
public:
    int ladderLength(string sd, string ed, vector<string>&dct) 
    {
        unordered_map<string,int>pp;
        for(auto it:dct)
        {
            pp[it]=INT_MAX;
        }
        int n=sd.size();
        pp[sd]=1;
        
        queue<pair<string,int>>pq;
        pq.push({sd,1});

        while(!pq.empty())
        {
            int d=pq.front().second;
            string st=pq.front().first;
            pq.pop();
            if(st==ed)
            return d;
            for(int i=0;i<n;i++)
            {
                char c1=st[i];
                for(char c='a';c<='z';c++)
                {
                    
                    st[i]=c;
                        if(pp.find(st)!=pp.end() && pp[st]>d+1)
                        {
                            pp[st]=d+1;
                            pq.push({st,pp[st]});
                        }
                    
                }
                st[i]=c1;
            }
            

        }
        return 0;
        

    }
};