class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int>ans;
        for(auto it:nums)
        {
            if(it==0)
            ans.push_back(it);
            else
            {
                stack<int>st;
                while(it>0)
                {
                    st.push(it%10);
                    it/=10;
                }
                while(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            
        }
        return ans;
        
    }
};