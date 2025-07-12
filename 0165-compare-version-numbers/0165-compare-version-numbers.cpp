#include<bits/stdc++.h>
class Solution {
public:
    int compareVersion(string v1, string v2) 
    {
        
        int i=0,j=0;
        int n1=v1.size(),n2=v2.size();
        while(i<n1 || j<n2)
        {
            int num1=0;
            int num2=0;
            while(i<n1 && v1[i]!='.' )
            {
                num1=num1*10+(v1[i]-'0');
                i++;
            }
            while(j<n2 && v2[j]!='.' )
            {
                num2=num2*10+(v2[j]-'0');
                j++;
            }
            
            // cout<<s1<<" "<<s2<<"&";
            if(num1>num2)
            return 1;
            else if(num1<num2)
            return -1;
            
            i++;
            j++;
        }
            return 0;
        
    }
};