class Solution {
public:
    int segments(int n, vector<int> p, int m)
    {
    map<int, int> c;
    c[0] = 1;
    bool has = false;
    int sum = 0;
    long long ans = 0;
    for (int r = 0; r < n; r++) {
 
        // If element is less than m
        if (p[r] < m)
            sum--;
 
        // If element greater than m
        else if (p[r] > m)
            sum++;
 
        // If m is found
        if (p[r] == m)
            has = true;
 
        // Count the answer
        if (has)
            ans+= c[sum] + c[sum - 1];
 
        // Increment sum
        else
            c[sum]++;
            cout<<sum<<" ";
    }
 
    return ans;
}
    int countSubarrays(vector<int>& nums, int k) {
        int res  = segments(nums.size(),nums,k);
        
        return res;
    }
};