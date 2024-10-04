class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> VV;
        int n=original.size();
        vector<vector<pair<long long,int>>>adj(26);
        for(int i=0;i<n;i++)
        {
            int c1=original[i]-'a';
            int c2=changed[i]-'a';
            int co=cost[i];
            adj[c1].push_back({c2,co});

        }
        for(int i=0;i<26;i++)
        {
            vector<long long> vv(26,LLONG_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0ll,i});
            vv[i]=0ll;
            while(!pq.empty())
            {
                int d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it1: adj[node])
                {
                    int n1=it1.first;
                    int d2=it1.second;
                    if(vv[n1]>d+d2)
                    {
                        vv[n1]=1ll*(d+d2);
                        pq.push({vv[n1],n1});
                    }
                }
            }
            // for(int i=0;i<26;i++)
            // {
            //     if(vv[i]==INT_MAX)
            //     {
            //         vv[i]=-1ll;
            //     }
            // }
            VV.push_back(vv);
        }
        int m=source.size();
        long long ans=0ll;
        for(int i=0;i<m;i++)
        {
            int c1=source[i]-'a';
            int c2=target[i]-'a';
            if(VV[c1][c2]==LLONG_MAX)
            return -1ll;
            ans+=VV[c1][c2];
        }
        return ans;
    }
};