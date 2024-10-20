class Solution {
public:
double call(string st,string end,unordered_map<string,vector<pair<string,double>>>&adj)
{
    if(adj.find(st)==adj.end()|| adj.find(end)==adj.end())
    return -1.0;
    unordered_map<string,int> vv;
    queue<pair<string,double>>pq;
    
    pq.push({st,1.0});
    vv[st]=1;
    while(!pq.empty())
    {
        string t1=pq.front().first;
        double p=pq.front().second;
        pq.pop();
        if(t1==end)
                return p;
        
        for(auto it: adj[t1])
        {
            
            string nw=it.first;
            double d1=it.second;
            if(vv.find(nw)==vv.end())
            {
                vv[nw]=1;
                pq.push({nw,p*1.0*d1});
            }
        }
    }
    
    return -1.0;
}
    vector<double> calcEquation(vector<vector<string>>& eq,
     vector<double>& val, vector<vector<string>>& q) 
    {
        int n=eq.size();
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<n;i++)
        {
            string x=eq[i][0];
            string y=eq[i][1];
            double wt=val[i];
            adj[x].push_back({y,wt});
            adj[y].push_back({x,1.0/wt});
        }
        vector<double> ans;
        for(auto it:q)
        {
            ans.push_back(call(it[0],it[1],adj));
        }
        return ans;
    }
};