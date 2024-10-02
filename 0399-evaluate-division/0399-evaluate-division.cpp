class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& qr) 
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        // vector<vector<pair<int,double>>> adj(26);
        int n=eq.size();
        for(int i=0;i<n;i++)
        {
            string x=eq[i][0];
            string y=eq[i][1];
            adj[x].push_back({y,val[i]});
            adj[y].push_back({x,1.0/val[i]});
        }
        
        vector<double> ans;
        for(auto it: qr)
        {
            string src=it[0];
            string tt=it[1];
            if(adj.find(src)==adj.end() || adj.find(tt)==adj.end())
            {
                ans.push_back(-1.0);
                continue;
            }
            queue<pair<string,double>>pq;
            pq.push({src,1.0});
            int m=0;
            unordered_map<string,int> vv;
            vv[src]=1;
            while(!pq.empty())
            {
                auto it1=pq.front();
                string node=it1.first;
                double d=it1.second;
                pq.pop();
                if(node==tt)
                {
                    ans.push_back(d);
                    m=1;
                    break;
                }
                for(auto it2: adj[node])
                {
                    string n1=it2.first;
                    double d2=it2.second;
                    if(vv.find(n1)==vv.end())
                    {
                        pq.push({n1,d2*d*1.0});
                        vv[n1]=1;
                    }
                    
                }
            }
            if(m==0)
            ans.push_back(-1.0);
        }
        return ans;
    }
};