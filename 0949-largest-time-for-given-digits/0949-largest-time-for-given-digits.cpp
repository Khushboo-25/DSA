class Solution {
public:
void call(vector<int>p1,vector<int>&ans)
{
    int h1=p1[0]*10+p1[1];
    int m1=p1[2]*10+p1[3];
    int h2=ans[0]*10+ans[1];
    int m2=ans[2]*10+ans[3];
    if(h1>=0 && m1>=0 && m1<=59 && h1<=23)
    {
        if(h1>h2)
        {
            for(int i=0;i<4;i++)
            {
                ans[i]=p1[i];
            }
        }
        else if(h1==h2 && m1>=m2)
        {
            for(int i=0;i<4;i++)
            {
                ans[i]=p1[i];
            }
        }
    }
}
    string largestTimeFromDigits(vector<int>& arr) 
    {
        vector<int>ans={-1,-1,-1,-1};
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i!=j)
                for(int k=0;k<4;k++)
                {
                    if(k!=i && k!=j)
                    for(int m=0;m<4;m++)
                    {
                        if(m!=i && m!=j && m!=k)
                        {
                            call({arr[i],arr[j],arr[k],arr[m]},ans);
                        }
                    }
                }
            }
        }
        if(ans[3]!=-1)
        {
            string ans1="";
            for(int i=0;i<4;i++)
            {
                char c='0';
                c+=ans[i];
                ans1+=c;
                if(i==1)
                {
                    ans1+=':';
                }
            }
            return ans1;
        }
        return "";
        
    }
};