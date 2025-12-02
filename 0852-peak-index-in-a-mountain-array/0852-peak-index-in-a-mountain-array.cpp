class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) 
    {
        int s=0,e=a.size()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(a[mid]>a[mid+1])
            {
                e=mid;
            }
            
            else
            s=mid+1;
        }
        
        return s;

        
    }
};