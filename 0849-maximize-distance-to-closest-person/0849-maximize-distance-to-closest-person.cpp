class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int n=seats.size();
        vector<int>lf(n,n),rf(n,n);
        int lt1=-n;
        for(int i=0;i<n;i++)
        {
            
            if(seats[i]==1)
            lt1=i;
            lf[i]=i-lt1;
        }
        lt1=2*n;
        for(int i=n-1;i>=0;i--)
        {
            
            if(seats[i]==1)
            lt1=i;
            rf[i]=lt1-i;
        }
        for(int i=0;i<n;i++)
        {
            cout<<lf[i]<<" "<<rf[i]<<endl;
            seats[i]=min(lf[i],rf[i]);

        }
        return *max_element(seats.begin(),seats.end());
        
    }
};