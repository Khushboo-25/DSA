class Solution {
public:
void call(int i,vector<vector<int>>&adj,int &cn,unordered_map<int,int>&rr,vector<int>&vv)
{
    rr[i]=cn;
    vv[i]=1;
    for(auto it: adj[i])
    {
        if(vv[it]==0)
        call(it,adj,cn,rr,vv);
    }
}
    bool equationsPossible(vector<string>& eq) 
    {
        set<pair<int,int>>pn,pc;
        for(auto it: eq)
        {
            int x=it[0]-'a';
            int y=it[3]-'a';
            if(it[1]=='=')
            {
                if(x>y)
                swap(x,y);
                if(x!=y)
                pc.insert({x,y});
            }
            else
            {
                if(x>y)
                swap(x,y);
                if(x!=y)
                pn.insert({x,y});
                else
                return 0;
            }
        }
        vector<vector<int>> adj(26);
        for(auto it: pc)
        {
            int x=it.first;
            int y=it.second;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        unordered_map<int,int>rr;
        vector<int>vv(26,0);
        int cn=1;
        for(int i=0;i<26;i++)
        {
            if(vv[i]==0)
            {
                call(i,adj,cn,rr,vv);
                cn++;
            }
        }
        for(auto it: pn)
        {
            int x=it.first;
            int y=it.second;
            if(rr[x]==rr[y])
            return 0;
        }
        return 1;

        
    }
};