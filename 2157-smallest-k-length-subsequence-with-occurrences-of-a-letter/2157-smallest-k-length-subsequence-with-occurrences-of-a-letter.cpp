class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        
        int n=s.size();
        vector<int>pf(n+1,0);

        for(int i=0;i<n;i++){
            pf[i+1]=pf[i]+int(s[i]==letter);
        }
        
        string str="";
        int in=0;
        for(int i=0;i<n;i++){
            while(!str.empty()&&str.back()>s[i]&&str.size()+n-i>k){
                if(str.back()==letter){
                    if(in+pf[n]-pf[i]-1>=repetition){
                        in--;
                        str.pop_back();
                    }
                    else break;
                }
                else str.pop_back();
            }
            str.push_back(s[i]);
            if(s[i]==letter)in++;
             while(str.size()+repetition-in>k)str.pop_back();
        }
        while(str.size()>k)str.pop_back();
        return str;
    }
};