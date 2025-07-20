class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int>pp;
        for(auto it: words)
        {
            pp[it]++;
        }
        vector<pair<int,string>>pp1;
        for(auto it: pp)
        {
            pp1.push_back({it.second,it.first});
        }
        sort(pp1.rbegin(),pp1.rend(),[](const pair<int,string> &a,const pair<int,string> &b){
            if(a.first==b.first)
            {
                return a.second>b.second;
            }
            return a.first < b.first;   
        });
        vector<string>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(pp1[i].second);
        }
        return ans;
        
    }
};