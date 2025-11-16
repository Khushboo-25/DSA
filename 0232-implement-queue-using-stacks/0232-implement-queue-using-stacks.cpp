class MyQueue {
    stack<int> a,b;
public:
    void push(int x) {
        b.push(x);
    }
    
    int pop() 
    {
        while(!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
        int x=-1;
        if(!a.empty())
        {
            x=a.top();
            a.pop();
        }
        
        while(!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
        return x;
    }
    
    int peek() {
       while(!b.empty())
        {
            a.push(b.top());
            {
                b.pop();
            }
        }
        int x=-1;
        if(!a.empty())
        {
            x=a.top();
        }
        
        while(!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
        return x;
    }
    
    bool empty() {
        if(b.empty())
        return 1;
        return 0;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */