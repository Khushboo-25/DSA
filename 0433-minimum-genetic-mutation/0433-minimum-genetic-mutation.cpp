class Solution {
public:
    int minMutation(string st, string ed, vector<string>& bk) 
    {
        int n=st.size();
        unordered_map<string,int>pp;
        unordered_map<string, int> ft;
        for(auto it: bk)
        {
            ft[it]=1;
        }
        priority_queue<pair<int,string>> qt;
        pp[st]=0;
        qt.push({0,st});
        while(!qt.empty())
        {
            string s1=qt.top().second;
            int mt=qt.top().first;
            qt.pop();
            for(int i=0;i<n;i++)
            {
               
                for(char c='A';c<='Z';c++)
                {
                    string s2=s1;
                    if(c!=s1[i])
                    {
                        s2[i]=c;
                        if(ft[s2]==1)
                        {
                            if(pp.find(s2)==pp.end())
                            {
                                pp[s2]=mt+1;
                                qt.push({mt+1,s2});
                            }
                            else if(pp[s2]>mt+1)
                            {
                                pp[s2]=mt+1;
                                qt.push({mt+1,s2});
                            }
                        }
                    }
                }
            }
        }
        if(pp.find(ed)==pp.end())
        return -1;
        return pp[ed];

        
    }
};