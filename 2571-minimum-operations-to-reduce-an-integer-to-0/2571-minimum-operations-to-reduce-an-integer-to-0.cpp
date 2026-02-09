class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        long long x = n;

        while (x > 0) {
            if (x % 2 == 0) {
                x /= 2;
            } 
            else 
            {
                if (x == 1) {
                    ans++;
                    break;
                }
                if ((x & 3) == 3)  // ends with 11
                    x++;
                else
                    x--;
                ans++;
            }
        }
        return ans;
    }
};
