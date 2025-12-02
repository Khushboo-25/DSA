class Solution {
public:
    int findKthLargest(vector<int>&n , int k){
        priority_queue<int,vector<int>> pq(n.begin(),n.end());
        int ans;
        while(k--){
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};