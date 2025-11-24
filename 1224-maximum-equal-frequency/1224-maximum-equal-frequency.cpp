class Solution {
public:

bool call(unordered_map<int,int> &fp) 
{
    // Case 1: only one frequency exists
    if(fp.size() == 1)
    {
        auto p = *fp.begin();
        int f = p.first;   // frequency
        int c = p.second;  // how many numbers have that frequency

        // valid if:
        // all numbers appear f times → total = f*c
        // OR all numbers appear exactly once
        if(f == 1 || c == 1)
            return true;

        return false;
    }

    // Case 2: exactly two different frequencies
    if(fp.size() == 2)
    {
        vector<pair<int,int>> ff;
        for(auto &it : fp)
            ff.push_back({it.first, it.second});

        sort(ff.begin(), ff.end());  
        // ff[0] = smaller freq
        // ff[1] = larger freq

        int f1 = ff[0].first, c1 = ff[0].second;
        int f2 = ff[1].first, c2 = ff[1].second;

        // Case A:
        // smaller freq is 1 and exactly one number has freq=1
        if(f1 == 1 && c1 == 1)
            return true;

        // Case B:
        // larger freq = smaller freq + 1  AND only one number has f2
        if(f2 == f1 + 1 && c2 == 1)
            return true;

        return false;
    }

    // More than 2 different frequencies → never valid
    return false;
}


int maxEqualFreq(vector<int>& nums) 
{
    int n = nums.size();
    unordered_map<int,int> freq;     // freq of numbers
    unordered_map<int,int> fp;       // freq → count of numbers with this freq

    int ans = 1;

    // process first element
    freq[nums[0]] = 1;
    fp[1] = 1;

    for(int i = 1; i < n; i++)
    {
        int x = nums[i];

        // old frequency of x
        int oldf = freq[x];

        // decrease count in fp
        if(oldf > 0)
        {
            if(fp[oldf] == 1) fp.erase(oldf);
            else fp[oldf]--;
        }

        // new frequency of x
        freq[x]++;
        int newf = freq[x];
        fp[newf]++;

        // check valid prefix
        if(call(fp))
            ans = i + 1;
    }

    return ans;
}
};
