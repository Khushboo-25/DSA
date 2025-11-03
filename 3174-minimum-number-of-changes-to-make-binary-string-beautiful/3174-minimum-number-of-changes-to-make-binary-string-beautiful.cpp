class Solution {
public:
    int minChanges(string a) 
    {
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            if(a[i]!=a[i+1])
            ans++;
        }
        return ans;
        
    }
};