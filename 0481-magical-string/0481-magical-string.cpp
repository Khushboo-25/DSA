class Solution {
public:
    int magicalString(int n) {
        if(n <= 3) return 1;

        string s = "122";
        int i = 2;       // pointer
        char add = '1';  // next char to add
        int ones = 1;    // count of '1'

        while(s.size() < n) {
            int cnt = s[i] - '0';  // how many times to add

            for(int j = 0; j < cnt && s.size() < n; j++) {
                s += add;
                if(add == '1') ones++;
            }

            add = (add == '1') ? '2' : '1';
            i++;
        }

        return ones;
    }
};