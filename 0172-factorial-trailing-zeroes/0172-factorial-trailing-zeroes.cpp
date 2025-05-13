class Solution {
public:
int mod=1e9+7;
    int trailingZeroes(int n) 
    {
        vector<int> count(n+1,0);
        count.push_back(0);
        int n5=0;
        for(int i=5;i<=n;i+=5)
        {
            
            
            int ans5=0;
            
                ans5=(ans5+count[i/5]%mod)%mod+1;
            count[i]=ans5;
            
            n5=n5+count[i];
            // cout<<ans2<<" "<<ans5<<endl;
        }
        
        
        return n5;



        // int count = 0;
        // while (n > 0) {
        //     n /= 5;
        //     count += n;
        // }
        // return count;

        
    }
};

