class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n = specialRoads.size();
        vector<pair<int,int>> pts;
        for (auto &s : specialRoads) {
            pts.push_back({s[0], s[1]});
            pts.push_back({s[2], s[3]});
        }
        
        pts.push_back({start[0], start[1]});
        pts.push_back({target[0], target[1]});
        
        unordered_map<long long, long long> dist;
        auto encode = [&](int x, int y) {
            return ((long long)x << 20) + y;
        };
        
        priority_queue<pair<long long, pair<int,int>>, vector<pair<long long, pair<int,int>>>, greater<>> pq;
        
        pq.push({0, {start[0], start[1]}});
        dist[encode(start[0], start[1])] = 0;
        
        long long ans = LLONG_MAX;
        
        while(!pq.empty()) {
            auto [d, p] = pq.top();
            pq.pop();
            int x = p.first, y = p.second;
            
            if (d > dist[encode(x, y)]) continue;
            
            ans = min(ans, d + abs(target[0]-x) + abs(target[1]-y));
            
            for (auto &s : specialRoads) {
                int x1 = s[0], y1 = s[1], x2 = s[2], y2 = s[3], cost = s[4];
                long long nd = d + abs(x - x1) + abs(y - y1) + cost;
                long long code = encode(x2, y2);
                if (!dist.count(code) || nd < dist[code]) {
                    dist[code] = nd;
                    pq.push({nd, {x2, y2}});
                }
            }
        }
        
        return (int)ans;
    }
};
