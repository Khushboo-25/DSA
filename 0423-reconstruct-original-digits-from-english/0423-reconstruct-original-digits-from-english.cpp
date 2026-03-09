class Solution {
public:
    string originalDigits(string s) 
    {
        /*
        
        */
        vector<string>st={
        "zero",//0
        "xis",//6
        "geiht",//8
        "htree",//3
        "two",//2
        "urfo",//4
        "one",//1
        "five",//5
        "seven",//7
        "nine"};//9
        unordered_map<char,int>pp;
        for(auto it:s)
        {
            pp[it]++;
        }
        string ans="";
        unordered_map<int,char>p2;
        p2[0]='0';
        p2[1]='6';
        p2[2]='8';
        p2[3]='3';
        p2[4]='2';
        p2[5]='4';
        p2[6]='1';
        p2[7]='5';
        p2[8]='7';
        p2[9]='9';

        for(int i=0;i<=9;i++)
        {
            char c=st[i][0];
            while(pp.find(c)!=pp.end() )
            {
                bool mp=1;
                for(auto it:st[i])
                {
                    pp[it]--;
                    if(pp[it]<=0)
                    {
                        mp=0;
                        pp.erase(it);
                    }
                }
                char c1='0'+i;
                ans+=p2[i];
                if(mp==0)
                break;
            }
        
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};