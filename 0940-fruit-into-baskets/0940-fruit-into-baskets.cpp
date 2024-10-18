class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int ans=0;
        int sum=0;
        int n=fruits.size();
        // queue<int>qt;
        unordered_map<int,int>pp;
        int s=0,e=0;
        while(e<n)
        {
            pp[fruits[e]]++;
            // sum=e-s+1;
            
            if(pp.size()<=2)
            {
                ans=max(e-s+1,ans);
            }
            else
            {
                while(pp.size()>2)
                {
                    if(pp[fruits[s]]>1)
                    {
                        pp[fruits[s]]--;
                    }
                    else
                    {
                        pp.erase(fruits[s]);
                    }
                    s++;
                }
            }
            e++;
            // ans=max(sum,ans);
        }
        return ans;
    }
};