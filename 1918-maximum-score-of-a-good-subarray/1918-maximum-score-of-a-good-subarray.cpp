class Solution {
public:
void update2(vector<int> &p1,int &n,vector<int> &nums)
{
    stack<pair<int,int>>cr;
    for(int i=n;i>=1;i--)
    {
        while(!cr.empty() && cr.top().first>=nums[i-1])
        {
            cr.pop();
        }
        if(!cr.empty())
        {
            p1[i]=cr.top().second;
        }
        else
        {
            p1[i]=n;
        }
        cr.push({nums[i-1],i-1});
    }
}
void update(vector<int> &p1,int &n,vector<int> &nums)
{
    stack<pair<int,int>>cr;
    for(int i=1;i<=n;i++)
    {
        while(!cr.empty() && cr.top().first>=nums[i-1])
        {
            cr.pop();
        }
        if(!cr.empty())
        {
            p1[i]=cr.top().second;
        }
        else
        {
            p1[i]=-1;
        }
        cr.push({nums[i-1],i-1});
    }
}
    int maximumScore(vector<int>& nums, int k) 
    {
        //     1 4 3 7 4 5
        //    -1 0 0 2 2 4
        //     n 2 n  
        int n=nums.size();
            vector<int>prevs(n+1,-1);
            vector<int> nexts(n+1,n);  
            update(prevs,n,nums);
            // for(auto it: prevs)
            // cout<<it<<" ";
            update2(nexts, n, nums);  
            // cout<<endl;
            // for(auto it: nexts)
            // cout<<it<<" ";
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                int s=prevs[i]+1;
                int e=nexts[i]-1;
                // s k  e
                // s e k 
                // k s e
                if(s<=k && k<=e)
                {
                    int val=nums[i-1];
                    ans=max(ans,val*(e-s+1));
                }
            }
            return ans;


        
    }
};