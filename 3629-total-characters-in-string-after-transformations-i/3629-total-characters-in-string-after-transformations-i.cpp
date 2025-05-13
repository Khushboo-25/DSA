class Solution {
public:
int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {

        vector<int> pp(26,0);
        for(auto it: s)
        {
            pp[it-'a']++;
        }
        int ln=0;
        while(t--)
        {
            vector<int>nw(26,0);
            for(int i=0;i<25;i++)
            {
                
                    nw[i+1]=pp[i];
                
            }
            
            nw[0]+=(nw[0]%mod+pp[25])%mod;
            nw[1]=(nw[1]%mod+pp[25])%mod;
            pp=nw;
            // for(auto it:pp)
            // {
            //     cout<<it<<" ";
            // }
            // cout<<endl;
        }
        for(auto it:pp)
        {
            ln=(ln%mod+it)%mod;
        }
        return ln;
        
    }
};