#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Check for almost duplicate within the current window
            auto it = st.lower_bound(nums[i] - valueDiff);
            
            // Check if this element is within `valueDiff`
            if (it != st.end() && abs(*it - nums[i]) <= valueDiff) {
                return true;
            }
            
            // Insert the current element into the set
            st.insert(nums[i]);

            // Maintain the size of the set to be `indexDiff`
            if (i >= indexDiff) {
                st.erase(st.find(nums[i - indexDiff]));
            }
        }
        
        return false;
    }
};
