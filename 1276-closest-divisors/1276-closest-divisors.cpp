class Solution {
public:
vector<int>call(int d)
{
    vector<int>ans;
    for(int i=1;i*i<=d;i++)
    {
        if(d%i==0)
        {
            ans={i,d/i};
        }
    }
    return ans;
}
    vector<int> closestDivisors(int num) 
    {
        vector<int> ans1=call(num+1);
        vector<int> ans2=call(num+2);
        if(ans1[1]-ans1[0]>ans2[1]-ans2[0])
        return ans2;
        return ans1;
    }
};