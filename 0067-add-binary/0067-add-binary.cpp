class Solution {
public:
    string addBinary(string a, string b) 
    {
        
        int l1=a.size()-1,l2=b.size()-1;
        int c=0;
        while(l1>=0 && l2>=0)
        {
            if(c==0)
            {
                if(a[l1]!=b[l2])
                {
                    b[l2]='1';
                }
                else if(a[l1]=='1')
                {
                    c=1;
                    b[l2]='0';
                }
            }
            else
            {
                if(a[l1]!=b[l2])
                {
                    b[l2]='0';
                    c=1;
                }
                else if(a[l1]=='1')
                {
                    c=1;
                    b[l2]='1';
                }
                else
                {
                    b[l2]='1';
                    c=0;
                }
            }
            l2--;
            l1--;
        }
        if(l1>=0)
        {
            while(l1>=0)
            {
                if(c==1)
                {
                    if(a[l1]=='1')
                    {
                        b='0'+b;
                        c=1;
                    }
                    else
                    {
                        b='1'+b;
                        c=0;
                    }
                }
                else 
                {
                    while(l1>=0)
                    {
                        b=a[l1]+b;
                        l1--;
                    }
                    
                }
                l1--;
                
            }

        }
        if(l2>=0)
        {
            while(l2>=0)
            {
                if(c==1)
                {
                    if(b[l2]=='1')
                    {
                        b[l2]='0';
                        c=1;
                    }
                    else
                    {
                        b[l2]='1';
                        c=0;
                    }
                }
                else 
                {
                    break;

                }
                l2--;
            }
        }
        if(c==1)
        {
            b='1'+b;
        }
        return b;
        
    }
    
};