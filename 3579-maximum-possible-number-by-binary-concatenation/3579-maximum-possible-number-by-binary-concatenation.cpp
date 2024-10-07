#include<bits/stdc++.h>
class Solution {
    private:
    string bin(int it)
    {
        string ans="";
        while(it)
        {
            if(it%2)
            {
                ans='1'+ans;
            }
            else
            ans='0'+ans;
            it/=2;
        }
        return ans;
    }
    int to_num(string s1)
    {
        int i=1;
        int ans=0;
        int n=s1.size();
        while(n>0)
        {
            if(s1[n-1]=='1')
            {
                ans+=i;
            }
            i*=2;
            n--;
        }
        return ans;
    }

public:
    int maxGoodNumber(vector<int>& nums) 
    {
        string s1=bin(nums[0]);
        string s2=bin(nums[1]);
        string s3=bin(nums[2]);
        int a=to_num(s1+s2+s3);
        int b=to_num(s1+s3+s2);
        int c=to_num(s2+s1+s3);
        int d=to_num(s2+s3+s1);
        int e=to_num(s3+s1+s2);
        int f=to_num(s3+s2+s1);
        return max({a,b,c,d,e,f});
    
        
        
    }
};