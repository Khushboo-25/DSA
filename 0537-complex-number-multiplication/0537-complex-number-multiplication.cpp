class Solution {
public:
int solve(string s)
{
    int p=1;
    int i=0;
    int ans=0;
    if(s[0]=='-')
    {
        p=-1;
        i++;
    }
    int n=s.size();
    for(int j=i;j<n;j++)
    {
        ans=ans*10+(s[j]-'0');
    }
    
    return ans*p;

}
    string complexNumberMultiply(string num1, string num2) 
    {
        int x1=1,y1=1;
        int x2=1,y2=1;
        int n1=num1.size(),n2=num2.size();
        string s1x="",s2x="";
        string s1y="",s2y="";
        int i=0,j=0;
        while(i<n1)
        {
            if(num1[i]=='+')
            {
                break;
            }
            i++;
        }
        while(j<n2)
        {
            if(num2[j]=='+')
            {
                break;
            }
            j++;
        }
        s1x+=num1.substr(0,i);
        s2x+=num2.substr(0,j);
        s1y+=num1.substr(i+1,n1-(i+2));
        s2y+=num2.substr(j+1,n2-(j+2));
        // cout<<s1x<<" "<<s1y<<endl;
        // cout<<s2x<<" "<<s2y<<endl;
        x1=solve(s1x),x2=solve(s2x);
        y1=solve(s1y),y2=solve(s2y);
        // cout<<x1<<" "<<y1<<endl;
        // cout<<x2<<" "<<y2<<endl;
        
        int real=x1*x2+(-1*y1*y2);
        int img=(x1*y2+x2*y1);
        return to_string(real)+"+"+to_string(img)+"i";
        
    }
};