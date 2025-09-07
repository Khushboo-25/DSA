class Solution {
public:
    vector<int> sumZero(int n) 
    {

        vector<int>a;
        for(int i=n/2;i>=1;i--)
        {
            a.push_back(-1*i);
        }
        if(n%2)
        {
            a.push_back(0);
        }
        for(int i=0;i<n/2;i++)
        {
            a.push_back(i+1);
        }
        return a;
        
    }
};