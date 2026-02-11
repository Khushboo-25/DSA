class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;
    
    for(int x : nums) {
        
        auto it = lower_bound(temp.begin(), temp.end(), x)-temp.begin();
        
        if(it == temp.size())
            temp.push_back(x);
        else
            temp[it]=x;
    }
    
    return temp.size();
}
};