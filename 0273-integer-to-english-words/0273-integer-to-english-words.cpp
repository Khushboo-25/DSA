class Solution {
public:

vector<string> oneToNineteen = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
    "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

vector<string> tens = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

string numberWords(int num) {
    string result="";

    if (num == 0) {
        result="Zero";
        return result;
    }
    int hundreds = num / 100;
    int lastTwo = num % 100;
    int t = lastTwo / 10;
    int ones = lastTwo % 10;
    string s1="";
    if (hundreds > 0) {
        s1+=oneToNineteen[hundreds]+" ";
        s1+="Hundred";
    }
    string s2="";
    if (lastTwo > 0) {
        if (lastTwo < 20) {
            s2+=oneToNineteen[lastTwo];
        } else {
            if (t > 0) s2+=tens[t];
            if (ones > 0) s2+=" "+oneToNineteen[ones];
        }
    }
    if(s1=="")
    return s2;
    else  if(s2=="")
    {
        return s1;
    }
    else
    return s1+" "+s2;

    return result;
}
    string numberToWords(int num) 
    {
        string s="";
        if(num==0)
        return "Zero";
        int cn=0;
        while(num>0)
        {
            string s1=numberWords(num%1000);
            if(cn==1 && s1!="Zero")
            {
                s1+=" Thousand";
            }
            else if(cn==2 && s1!="Zero")
            {
                s1+=" Million";
            }
            else if(cn==3 && s1!="Zero")
            {
                s1+=" Billion";
            }
            if(s.empty())
            {
                if(s1!="Zero")
                {
                    s=s1;
                }
            }
            else
            {
                if(s1!="Zero")
                {
                    s=s1+" "+s;
                }
            }
            cn++;
            
            num/=1000;
        }
        return s;
        
    }
};