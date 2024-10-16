class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) 
    {
        int n2=b.size(),n1=a.size();
        unordered_map<int,int> pp;
        for(int i=0;i<n2;i++)
        {
                int t=i+1,u=0;
                while(t<n2)
                {
                    if(b[i]<b[t])
                    {
                        pp[b[i]]=b[t];
                        u=-1;
                        break;
                    }
                    t++;
                }
                if(u==0)
                pp[b[i]]=-1;
        }
        for(int i=0;i<n1;i++)
        {
            a[i]=pp[a[i]];
        }
        return a;
        
    }
};