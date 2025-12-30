class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string s1="";
        int n=s.size();
        int n1=0;
        for(int i=0;i<n;i++)
        {
            if(n1<spaces.size() && i==spaces[n1])
            {
                s1+=' ';
                n1++;
            }
            s1+=s[i];
        }
        return s1;
    }
};