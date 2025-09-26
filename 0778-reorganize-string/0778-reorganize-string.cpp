class Solution {
public:
    string reorganizeString(string s) 
    {
        unordered_map<char,int>pp;
        for(auto it:s)
        {
            pp[it]++;
        }
        vector<pair<int,char>>p1;
        for(auto it:pp)
        {
            p1.push_back({it.second,it.first});
        }
        sort(p1.rbegin(),p1.rend());
        int n=s.size();
        s="";
        for(auto it:p1)
        {
            while(it.first--)
            {
                s+=it.second;
            }
        }
        string s1=s;
        int ci=0;
        for(int i=0;i<n;i+=2)
        {
            s1[i]=s[ci];
            ci++;
        }
        for(int i=1;i<n;i+=2)
        {
            s1[i]=s[ci];
            ci++;
        }

        for(int i=1;i<n;i++)
        {
            if(s1[i]==s1[i-1])
            return "";
        }
        return s1;
        
    }
};