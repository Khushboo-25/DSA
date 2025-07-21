class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pp;
        int e=INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            // num,rol,col 0
            pp.push({nums[i][0], i, 0});

            e = max(e, nums[i][0]);
        }
        vector<int> ans = {0, INT_MAX};

        while (!pp.empty()) {
            
            vector<int> curr = pp.top();
            pp.pop();
            int s = curr[0], listIdx = curr[1], elemIdx = curr[2];

            if (e - s < ans[1] - ans[0]) {
                ans[0] = s;
                ans[1] = e;
            }
            if (elemIdx + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][elemIdx + 1];
                pp.push({nextVal, listIdx, elemIdx + 1});
                e = max(e, nextVal);
            } else {
                break;
            }
        }
        return ans;
    }
};