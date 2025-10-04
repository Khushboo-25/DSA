class Solution {
public:
    int minDeletions(string s) 
    {
        unordered_map<char,int>pp;
        for(auto it: s)
        pp[it]++;
        vector<int>vv;
        for(auto it:pp)
        {
            vv.push_back(it.second);
        }
        sort(vv.rbegin(),vv.rend());
        int n=vv.size();
        int ans=0;
        int pv=vv[0];
        for(int i=1;i<n;i++)
        {
            if (vv[i] >= pv) 
            {
                int allowed = max(0, pv - 1);
                ans += vv[i] - allowed;
                pv = allowed;
            } 
            else 
            {
                pv = vv[i];
            }
        }
        return ans;
        
    }
};