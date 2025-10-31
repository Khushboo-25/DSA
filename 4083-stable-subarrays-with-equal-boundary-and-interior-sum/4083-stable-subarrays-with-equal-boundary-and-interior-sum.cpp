class Solution {
public:
    long long countStableSubarrays(vector<int>& cap) 
    {
        int n=cap.size();
        unordered_map<string,int>pp;
        // val ,sum-2*val
        long long sum1=cap[0]+cap[1], sum=cap[0];
        long long ans=0;
        for(int i=2;i<n;i++)
        {
            sum1+=cap[i];
            string s=to_string(cap[i-2]); // val 
            string ps=to_string(sum); // sum i-2
            sum+=cap[i-1];
            pp[s+','+ps]++; 
            string t=to_string(cap[i]); 
            string ts=to_string(sum1-2*cap[i]); 
            ans+=pp[t+','+ts]; 

        }
        return ans;
        
        
    }
};