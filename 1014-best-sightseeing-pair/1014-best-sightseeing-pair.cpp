class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int>mx(n,0);
        mx[0]=arr[0];
        int ans=INT_MIN;
        for(int j=1;j<n;j++)
        {
            ans=max(ans,mx[j-1]+arr[j]-j);
            mx[j]=max(mx[j-1],arr[j]+j);
        }
        return ans;

        
    }
};