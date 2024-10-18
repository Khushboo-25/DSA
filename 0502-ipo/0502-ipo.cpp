// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
//         vector<pair<int,int>>pp;
//         int n=p.size();
//         for(int i=0;i<n;i++)
//         {
//             pp.push({c[i],p[i]});
//         }
//         sort(pp.begin().pp.end());
//         int s=0;
//         priority_queue<int>pq;
//         while(k--)
//         {
//             if(pp[s].first<=w)
//             {

//             }
//         }
//     }
// };

class Solution {
public:
// int call(int in,int k,int crw,vector<int> &p,vector<int> &cap,int &n)
// {
//     if(in>=p.size() || k==0)
//     {
//         return crw;
//     }
//     // if(dp[in][k]!=-1)
//     // return dp[in][k];
//     int ans=0;
//     if(crw<cap[in])
//     {
//         int w1=call(in+1,k,crw,p,cap,n);
//         ans=max(w1,ans);
//     }
//     else 
//     {
//         int w1=call(in+1,k-1,crw+p[in],p,cap,n);
//         int w2=call(in+1,k,crw,p,cap,n);
//         ans=max(ans,max(w1,w2));
//     }
//     return ans;
// }
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& cap) 
    {
        map<int,vector<int>>pp;
        int n=p.size();
        for(int i=0;i<n;i++)
        {
            pp[cap[i]].push_back(p[i]);
        }
        // int n=pp.size();
        
        priority_queue<int>pq;
        // unordered_map<int,bool>mark;
        auto it=pp.begin();
        while(k>0)
        {
            while(it!=pp.end())
            {
                auto it1=*it;
                if(it1.first<=w)
                {
                    for(auto it2:it1.second)
                    pq.push(it2);
                    // mark[it.first]=1;
                    it++;
                }
                else
                break;
                // break;
            }
            if(pq.empty())
            break;
            w+=pq.top();
            pq.pop();
            k--;
            
        }
        return w;
    }
};