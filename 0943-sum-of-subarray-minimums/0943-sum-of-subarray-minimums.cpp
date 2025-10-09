class Solution {
public:
void call1(vector<int> &left,int n,vector<int> &arr)
{
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            left[i]=st.top();
        }
        else
        left[i]=-1;
        st.push(i);
    }

}
void call2(vector<int> &right,int n,vector<int> &arr)
{
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            right[i]=st.top();
        }
        else
        right[i]=n;
        st.push(i);
    }
}
int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> left(n);
        vector<int> right(n);
        call1(left,n,arr);
        for(int i=0;i<n;i++)
        {
            cout<<left[i]<<" ";
            left[i]=abs(left[i]-i);
            // cout<<left[i]<<" ";
        }
        
        cout<<endl;
        
        int ans=0;
        call2(right,n,arr);
         for(int i=0;i<n;i++)
        {
            // cout<<right[i]<<" ";
            right[i]=abs(right[i]-i);
            cout<<right[i]<<" ";
        }
        for(int i=0;i<n;i++)
        {
            ans=(ans+((left[i]*1ll*right[i])%MOD*1ll*arr[i])%MOD)%MOD;
        }
        return ans;
        // call2(right,n,arr);

    }
};