class Solution {
public:
    string shiftingLetters(string s, vector<int>& sh) 
    {
        
        int n=s.size();
        sh[n-1]=sh[n-1]%26;
        for(int i=n-2;i>=0;i--)
        {
            sh[i]=(sh[i+1]+sh[i])%26;
        }
        for(int i=0;i<n;i++)
        {
            int cr=s[i]-'a';
            cr+=sh[i];
            cr=cr%26;
            s[i]='a'+cr;
        }
        return s;
        
    }
};