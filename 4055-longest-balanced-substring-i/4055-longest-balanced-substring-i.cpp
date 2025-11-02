class Solution {
public:
    int longestBalanced(string s) 
    {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>pp;
            unordered_map<int,int>fp;
            for(int j=i;j<n;j++)
            {
                int fpre=pp[s[j]];
               // cout<<fpre<<" ";
                pp[s[j]]++;
                int fnew=pp[s[j]];
                if(fp[fpre]>=1)
                {
                    fp[fpre]--;
                }
                if(fp[fpre]==0)
                fp.erase(fpre);
                fp[fnew]++;
                if(fp.size()==1)
                ans=max(ans,j-i+1);
            }
        }
        return ans;
        
    }
};