class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        int n=words.size();
        vector<string>ans;
        ans.push_back(words[0]);
        string ls=words[0];
        sort(ls.begin(),ls.end());
        for(int i=1;i<n;i++)
        {
            string s1=words[i];
            sort(s1.begin(),s1.end());
            if(s1!=ls)
            ans.push_back(words[i]);
            ls=s1;
        }
        return ans;
        
        
    }
};