class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n=pushed.size(),m=popped.size();
        int i=0,j=0;
        for(int i=0;i<n;i++)
        {
            st.push(pushed[i]);
            while(j<m && !st.empty() && st.top()==popped[j])
            {
                j++;
                st.pop();
            }
        }
        if(!st.empty())
        return 0;
        return 1;
    }
};