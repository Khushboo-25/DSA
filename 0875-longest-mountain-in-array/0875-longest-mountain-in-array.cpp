class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return 0;

        int max_length = 0;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                int left = i, right = i;

                while (left > 0 && nums[left - 1] < nums[left]) {
                    left--;
                }

                while (right < n - 1 && nums[right + 1] < nums[right]) {
                    right++;
                }

                int length = right - left + 1;
                max_length = max(max_length, length);
            }
        }
        
        return max_length;
    }
};
