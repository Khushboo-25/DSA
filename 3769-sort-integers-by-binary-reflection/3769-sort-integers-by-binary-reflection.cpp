class Solution {
public:
static bool cmp(const pair<string,int>&p1,const pair<string,int>&p2)
{
    if(p1.first.size()<p2.first.size())
    return 1;
    if(p1.first.size()==p2.first.size())
    {
        if(p1.first<p2.first)
        {
            return 1;
        }
        else if(p1.first==p2.first)
        {
            return p1.second<=p2.second;
        }
    }
    
    return 0;
}
    vector<int> sortByReflection(vector<int>& nums) 
    {
        vector<pair<string,int>>pp;
        for(auto it: nums)
        {
            // int t=32;
            int k=it;
            string s1="";
            while(it>0)
            {
                if(it%2)
                s1+='1';
                else if(!s1.empty())
                s1+='0';
                it=it/2;
            }
            // reverse(s1.begin(),s1.end());
            pp.push_back({s1,k});
        }
        sort(pp.begin(),pp.end(),cmp);
        vector<int>ans;
        for(auto it: pp)
        {
            cout<<it.first<<" "<<it.second<<endl;
            ans.push_back(it.second);
        }
        return ans;
    }
};