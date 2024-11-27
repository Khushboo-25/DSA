class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        
        set<string> st;
        unordered_map<int,bool>pp;
        int n=s.size();
        unordered_map<char,int>pc;
        pc['A']=1;
        pc['C']=2;
        pc['G']=3;
        pc['T']=4;
        int hash1=0;
        for(int i=0;i<10;i++)
        {
            hash1+=pc[s[i]]*pow(5,i);
            
        }
        pp[hash1]=1;
        for(int i=10;i<n;i++)
        {
            
            int nwh=hash1/5+(pc[s[i]])*pow(5,9);
            if(pp[nwh]==1)
            {
                st.insert(s.substr(i-9,10));
            }
            else
            {
                pp[nwh]=1;
            }
            hash1=nwh;
        }
        vector<string> ans;
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
        
        
    }
};