class Solution {
public:
    long long smallestNumber(long long num) 
    {
        if (num == 0) return 0;

        bool neg = (num < 0);
        string s = to_string(llabs(num));

        if (!neg)
        {
            // positive: smallest number, no leading zero
            sort(s.begin(), s.end());

            int idx = 0;
            while (idx < s.size() && s[idx] == '0') idx++;

            // place first non-zero digit in front
            if (idx < s.size())
                swap(s[0], s[idx]);
        }
        else
        {
            // negative: largest number, then add '-'
            sort(s.begin(), s.end(), greater<char>());
        }

        long long ans = stoll(s);
        return neg ? -ans : ans;
    }
};
