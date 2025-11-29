class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if (s.size() != goal.size()) 
            return false;
        
        // Concatenate s with itself
        string ss = s + s;
        
        // Check if goal is a substring of the concatenated string
        return ss.find(goal) != string::npos;
    }
};