class Solution {
public:
    int maximumSwap(int num) 
    {
        string s=to_string(num);
        string ans=s;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            
            for(int j=i+1;j<n;j++)
            {
                string s1=s;
                swap(s1[i],s1[j]);
                ans=max(ans,s1);
            }
        }
        int num1=0;
        for(auto it: ans)
        {
            num1=num1*10+(it-'0');
        }
        return num1;
        
    }
};