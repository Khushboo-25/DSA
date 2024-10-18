class Solution {
public:
    bool equalFrequency(string word) 
    {
        unordered_map<char,int>pp;
        for(auto it:word)
        {
            pp[it]++;
        }
        for(auto &it: pp)
        {
            it.second--;
            unordered_map<int,int>pp1;
            for(auto it:pp)
            {
                if(it.second!=0)
                pp1[it.second]++;
            }
            if(pp1.size()<=1)
            return 1;
            it.second++;
        }
        return 0;
        
        
    }
};