class Solution {
public:
    string make_string(vector<int> &v){
        string ans = "";
        for(auto it:v) ans += (it +'0');
        return ans;
        
    }
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.rbegin(),digits.rend());
        int n = digits.size();
        int sum = accumulate(digits.begin(),digits.end(),0);
        if(sum == 0) return "0";
        if(sum %3  == 0) return make_string(digits);
        int one = 0,two = 0;
        map<int,vector<int>> m;

        for(auto it:digits){
             if((it%3) == 1) {m[1].push_back(it);one++;}
             else if((it%3) == 2) {m[2].push_back(it);two++;}
             else m[0].push_back(it);
        }
        if(sum%3 == 1){
            if(!m[1].empty()) m[1].pop_back();
            else {
                m[2].pop_back();
                m[2].pop_back();
            }
        }
        else {
            if(!m[2].empty()) m[2].pop_back();
            else {
                m[1].pop_back();
                m[1].pop_back();
            }
        }
        string ans = "";
        for(int i = 0;i<3;i++){
            for(auto it:m[i]){
                ans += (it + '0');
            }
        }
        sort(ans.rbegin(),ans.rend());
        if(ans[0] == '0') return "0";
        return ans;
         

    }
};