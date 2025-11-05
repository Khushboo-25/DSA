class Solution {
public:
    int maximumLength(string s) 
    {
        vector<priority_queue<int>>fq(26);
        char c=s[0];
        int f=1;
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            if(s[i]!=c)
            {
                fq[c-'a'].push(f);
                f=1;
                c=s[i];
            }
            else
            {
                f++;
            }
        }
        int ans=-1;
        fq[c-'a'].push(f);
        for(int i=0;i<26;i++)
        {
            int f1=-1,f2=-1,f3=-1;
            if(!fq[i].empty())
            {
                f1=fq[i].top();
                fq[i].pop();
            }
            if(!fq[i].empty())
            {
                f2=fq[i].top();
                fq[i].pop();
            }
            if(!fq[i].empty())
            {
                f3=fq[i].top();
                fq[i].pop();
            }
            if(f3!=-1)
            {
                ans=max(f3,ans);
                
            }
            if(f2!=-1)
            {
                if(f1>f2)
                ans=max(ans,f2);
                else if(f1==f2)
                ans=max(f1-1,ans);

            }
            if(f1!=-1)
            {
                ans=max(ans,f1-2);
            }
        }
        return ans>0?ans:-1;




    }
};