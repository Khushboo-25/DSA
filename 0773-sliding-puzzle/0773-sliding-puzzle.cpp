class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string start = "";
        for(auto &row : board)
            for(int x : row)
                start += char('0' + x);

        string goal = "123450";

        vector<vector<int>> moves = {
            {1,3},    // 0
            {0,2,4},  // 1
            {1,5},    // 2
            {0,4},    // 3
            {3,1,5},  // 4
            {2,4}     // 5
        };

        queue<string> q;
        unordered_map<string,int> dist;

        dist[start] = 0;
        q.push(start);

        while(!q.empty())
        {
            string s = q.front(); q.pop();
            if(s == goal) return dist[s];

            int z = s.find('0');

            for(int nxt : moves[z])
            {
                string t = s;
                swap(t[z], t[nxt]);

                if(!dist.count(t))
                {
                    dist[t] = dist[s] + 1;
                    q.push(t);
                }
            }
        }

        return -1;
    }
};
