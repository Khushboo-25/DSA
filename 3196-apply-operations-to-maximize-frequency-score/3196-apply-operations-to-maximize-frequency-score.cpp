class Solution {
public:
bool check(int ln,vector<int>&nums,long long  k,vector<long long>&prev,int &n)
{
    // int m1=-1,m2=-1;
    
    for(int i=ln-1;i<n;i++)
    {
        int s=i-ln+1;
        int e=i;
       
            int m1=s+(e-s)/2;
            int leftlen=m1-s;
            int rightlen=e-m1;
            long long leftsum=0;
            if(m1-1>=0)
            leftsum+=prev[m1-1];
            // s   m1   e
            if(s-1>=0)
            leftsum-=prev[s-1];
            long long rightsum=prev[e]-prev[m1];
            long long leftop=leftlen*1ll*nums[m1]-leftsum;
            long long rightop=rightsum-rightlen*1ll*nums[m1];
            if(leftop+rightop<=k)
            return 1;
            
        
    }
    return 0;
}
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<long long>prev(n,0);
        prev[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prev[i]=prev[i-1]+nums[i];
        }
        int ans=0;
        int s=1,e=n;
        while(s<=e)
        {
            int len=s+(e-s)/2;
            if(check(len,nums,k,prev,n))
            {
                ans=len;
                s=len+1;
            }
            else
            {
                e=len-1;
            }
        }
        return ans;
    }
};