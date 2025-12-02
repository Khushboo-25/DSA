class Solution {
public:
    int search(vector<int>& a, int t) 
    { 
        int s=0,l=a.size()-1;
        int mid=l/2;
        while(s<=l)
        {
            if(s<=l)
            {

                mid=s+(l-s)/2;
                if(a[mid]==t)
                return mid;
                else if(t<a[mid])
                {
                    l=mid-1;
                }
                else
                {
                    s=mid+1;
                }

            }
            
        } 
            return -1; 
    }
};