#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> pos;

    RandomizedSet() 
    {

    }

    bool insert(int val) {
        if (pos.find(val) != pos.end()) return false;
        nums.push_back(val);
        pos[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (pos.find(val) == pos.end()) return false;
        int idx = pos[val];
        int last = nums.back();

        // Swap val with last element
        nums[idx] = last;
        pos[last] = idx;

        nums.pop_back();
        pos.erase(val);
        return true;
    }

    int getRandom() {
        int r = rand() % nums.size();
        return nums[r];
    }
};
