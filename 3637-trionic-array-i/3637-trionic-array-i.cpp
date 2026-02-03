class Solution {
public:
    bool isTrionic(vector<int>& a) 
    {
        int i=0;
        int n=a.size();
        while(i+1<n && a[i+1]>a[i])
        i++;
        int p=i;
        int j=n-1;
        while(j-1>=0 && a[j-1]<a[j])
        {
            j--;
        }
        int q=j;
        bool ps=1;
        for(int k=p+1;k<=q;k++)
        {
            if(a[k]>=a[k-1])
            {
                return 0;
            }
        }
        if(p!=0 && q!=n-1 && p<q)
        return 1;
        return 0;
        
    }
};