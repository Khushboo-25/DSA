class Solution {
public:
    int lastStoneWeight(vector<int>& st) 
    {
        priority_queue<int>pq;
        for(auto it: st)
        {
            pq.push(it);
        }
        while(pq.size()>1)
        {
            int x1=pq.top();
            pq.pop();
            int y1=pq.top();
            pq.pop();
            if(x1!=y1)
            {
                pq.push(x1-y1);
            }
        }
        if(pq.empty())
        return 0;
        return pq.top();
        
    }
};