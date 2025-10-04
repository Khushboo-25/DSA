class Solution {
public:
    vector<int> minOperations(string &bx) 
    {
        int n=bx.size();
        vector<int>lf(n,0);
        
        int cn=(bx[0]-'0');
        for(int i=1;i<n;i++)
        {
            lf[i]=lf[i-1]+cn;
            cout<<lf[i]<<" ";
            if(bx[i]=='1')
            cn++;
        }
        cout<<endl;
        vector<int>rf(n,0);
        cn=(bx[n-1]-'0');
        for(int i=n-2;i>=0;i--)
        {
            
            rf[i]=rf[i+1]+cn;
            if(bx[i]=='1')
            cn++;
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]+=lf[i]+rf[i];
        }
        return ans;


    }
};