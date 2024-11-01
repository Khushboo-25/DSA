class Solution {
public:
    string makeLargestSpecial(string s) {
        
        if(s.length()==0)
            return ""; 

        vector<string> ans; 
        int count=0,i=0; 

        for(int j=0;j<s.size();j++){
            if(s[j] == '1')
                count++;
            else
                count--;
            
            if(count==0){
                ans.push_back('1' + makeLargestSpecial(s.substr(i+1,j-i-1)) + '0');
                i = j+1;
            }
        }

        sort(ans.rbegin(),ans.rend());
        string finalString = "";
        for(i=0;i<ans.size();i++){
            finalString += ans[i];
        }
        return finalString;
    }
};
