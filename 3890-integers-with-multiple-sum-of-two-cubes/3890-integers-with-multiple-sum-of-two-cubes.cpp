class Solution {
public:
    vector<int> findGoodIntegers(int n) 
    {
        // n=1e9;
        vector<int>av;
        for(int i=1;;i++)
        {
            int mv=i*i*i;
            if(mv>=n)
            break;
            av.push_back(i*i*i);
        }
        // cout<<av.size();
        unordered_map<int,int>pp;
        int n1=av.size();
        for(int j=0;j<n1-1;j++)
        {
            for(int k=j;k<n1;k++)
            {
                if(av[j]+av[k]<=n)
                pp[av[j]+av[k]]++;
            }
        }
        vector<int>ans;
        for(auto it:pp)
        {
            if(it.second>1)
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};