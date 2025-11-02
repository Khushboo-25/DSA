class Solution {
public:
class Node{
    public: 
    int val;
    Node* next;
    Node(int d)
    {
        this->val=d;
        this->next=NULL;
    }
};
class Nodec{
    public: 
    char val;
    Nodec* next;
    Nodec(char d)
    {
        this->val=d;
        this->next=NULL;
    }
};
void update(Node* links, Nodec* chars)
{
    Node* l1=links->next;
    Nodec* c1=chars;

    
    while(l1 && c1)
    {
        if(c1->next && c1->next->val=='/')
        {
            int d=l1->val/l1->next->val;
            l1->val=d;
            l1->next=l1->next->next;
            c1->next=c1->next->next;
        }
        else if(c1->next && c1->next->val=='*')
        {
            int d=l1->val*l1->next->val;
            l1->val=d;
            l1->next=l1->next->next;
            c1->next=c1->next->next;
        }
        else
        {
            l1=l1->next;
            c1=c1->next;
        }
    }
    
    l1=links->next;
    c1=chars->next;

    int ans=l1->val;
    l1=l1->next;
    while(c1)
    {
        if(c1->val=='+')
        {
            ans+=l1->val;
        }
        else
        {
            ans-=l1->val;
        }
        l1=l1->next;
        c1=c1->next;
    }
    // while(links)
    // {
    //     cout<<links->val<<" ";
    //     links=links->next;
    // }
    //     while(chars)
    //     {
    //         cout<<chars->val<<" ";
    //         chars=chars->next;
    //     }
     
    links->next=new Node(ans);
}
int solve(Node* links,Nodec* chars)
{
    update(links,chars);
    // return 0;
    return links->next->val;

}
    int calculate(string s) {
        Node* links=new Node(0);
        Nodec* chars=new Nodec('`');
        Node* p1=links;
        Nodec* p2=chars;
        int n=s.size();

        int num=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]<='9' && s[i]>='0')
            {
                num=num*10+(s[i]-'0');
            }
            else if(s[i]!=' ')
            {
                p1->next=new Node(num);
                p1=p1->next;
                p2->next=new Nodec(s[i]);
                p2=p2->next;
                num=0;
            }
        }
            p1->next=new Node(num);
            p1=p1->next;
        

    //    
        return solve(links,chars);
    }
};