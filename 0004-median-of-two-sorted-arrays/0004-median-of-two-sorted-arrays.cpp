class Solution {
public:
bool call1(int m,vector<int>&nm1,vector<int>&nm2,int &n1,int &n2)
{
    int cn1=(upper_bound(nm1.begin(),nm1.end(),m)-nm1.begin());
    int cn2=(upper_bound(nm2.begin(),nm2.end(),m)-nm2.begin());
    if((cn1+cn2)>=(n1+n2)/2)
    return 1;
    return 0;

}
bool call2(int m,vector<int>&nm1,vector<int>&nm2,int &n1,int &n2)
{
    int cn1=lower_bound(nm1.begin(),nm1.end(),m)-nm1.begin();
    int cn2=lower_bound(nm2.begin(),nm2.end(),m)-nm2.begin();
    if(cn1+cn2<=(n1+n2)/2)
    return 1;
    return 0;

}
    double findMedianSortedArrays(vector<int>& nm1, vector<int>& nm2) 
    {
        int n1=nm1.size(),n2=nm2.size();
        int a1=-1e6;// <=m+n/2;
        int b1=1e6; //>=m+n/2;
        int s=-1e6,e=1e6;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(call2(m,nm1,nm2,n1,n2))
            {
                a1=m;
                s=m+1;
            }
            else
            e=m-1;
        }
        s=-1e6,e=1e6;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(call1(m,nm1,nm2,n1,n2))
            {
                b1=m;
                e=m-1;
            }
            else
            s=m+1;
        }
        cout<<a1<<" "<<b1;
        if((n1+n2)%2==0)
        return ((a1+b1)*1.0)/2;
        return a1;
        // return ((a1+b1)*1.0)/2;

    }
};