class Solution {
public:
void merge(vector<int> &arr,int l,int m,int r,int &ans)
    {
        
        vector<int> arr2(r-l+1);
        int  k=0;
        int l1=l;
        int l2=m+1;
        for (int i = l; i <= m; i++) 
        {
            while (l2 <= r && arr[i] > 2LL * arr[l2]) 
            {
                l2++;
            }
            ans += (l2 - (m + 1));
        }
        l2=m+1;
        while(l1<=m && l2<=r)
        {
            if(arr[l1]<=arr[l2])
            {
                arr2[k]=arr[l1];
                k++;
                l1++;
            }
            else
            {
                arr2[k]=arr[l2];
                k++;
                l2++;
                
            }
            
        }
        while(l1<=m)
        {
            arr2[k]=arr[l1];
                k++;
                l1++;
        }
        while(l2<=r)
        {
            arr2[k]=arr[l2];
                k++;
                l2++;
        }
        for(int i=l;i<=r;i++)
        {
            arr[i]=arr2[i-l];
        }
    }
    void mergeSort(vector<int> &arr,int l,int r,int &ans)
    {
        if(l<r)
        {
            int m=l+(r-l)/2;
            mergeSort(arr,l,m,ans);
            mergeSort(arr,m+1,r,ans);
            merge(arr,l,m,r,ans);
        }
    }
    int reversePairs(vector<int>& nums) 
    {
        int ans=0;
        
        int n=nums.size();
        
        mergeSort(nums,0,n-1,ans);
        
        return ans;

        
    }
};