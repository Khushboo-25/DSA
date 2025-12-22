class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
    long long even = 0, odd = 0;
    for (int x : nums) {
        long long ne = max(even, odd + x);
        long long no = max(odd, even - x);
        even = ne;
        odd = no;
    }
    return even;
}

};