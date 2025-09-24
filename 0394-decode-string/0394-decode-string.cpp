#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0; // index ref
        return decode(s, i);
    }

    string decode(const string& s, int& i) 
    {
      string ans="";
      int n=s.size();
      int num=0;
      while(i<n)
      {
        
        if(isdigit(s[i]))
        {
            num=num*10+(s[i]-'0');
            i++;
        }
        else if(s[i]=='[')
        {
            i++;
            string ans1=decode(s,i);
            for(int j=0;j<num;j++)
            {
                ans+=ans1;
            }
            num=0;
        }
        else if(s[i]==']')
        {
            i++;
            return ans;
        }
        else
        {
            
            ans+=s[i];
            i++;
        }
      }

      return ans;
    }
};