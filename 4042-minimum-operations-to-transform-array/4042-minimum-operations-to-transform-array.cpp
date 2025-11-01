class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) 
    {
        long long ans=0;
        int n=nums1.size();
        int p=nums2[n];
        
        int add=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int d=abs(nums1[i]-nums2[i]);
            ans+=d;
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(nums1[i]<=nums2[i])     
            {
                if(p<=nums1[i])    /// p n1 n2
                {
                    int dp=abs(nums1[i]-p);
                    add=min(add,dp+1);
                }
                else if(p>nums2[i])   // n1 n2 p
                {
                    int dn=abs(nums2[i]-p);
                    add=min(add,dn+1);
                }
                else///n1 p n2
                {
                    add=min(add,1);
                }
            }
            else
            {
                if(p<=nums2[i])    // p n2 n1 
                {
                    int dp=abs(nums2[i]-p);
                    add=min(add,dp+1);
                }
                else if(p>nums1[i]) // n2 n1 p
                {
                    int dn=abs(nums1[i]-p);
                    add=min(add,dn+1);
                }
                else //n2 p n1
                {
                    add=min(add,1);
                }
            }
        }
    
        return ans+add;
        
    }
};