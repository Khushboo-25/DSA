#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            auto it = st.lower_bound(nums[i] - valueDiff);
            
            if (it != st.end() && abs(*it - nums[i]) <= valueDiff) {
                return true;
            }
            
            st.insert(nums[i]);

            if (i >= indexDiff) {
                st.erase(st.find(nums[i - indexDiff]));
            }
        }
        
        return false;
    }
};
