class Solution {
public:
int f(vector<int>&height){
    int n = height.size();
    int leftsmall[n],rightsmall[n];
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
        if(st.empty()) leftsmall[i]=0;
        else 
        leftsmall[i] = st.top()+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
        if(st.empty()) rightsmall[i]=n-1;
        else rightsmall[i] = st.top()-1;
        st.push(i);
    }
    for(auto it:height)
    cout<<it<<" ";
    cout<<endl;
    for(auto it:leftsmall)
    cout<<it<<" ";
    cout<<endl;
    for(auto it:rightsmall)
    cout<<it<<" ";
    cout<<endl;

    int maxans =0;
    for(int i=0;i<n;i++){
        maxans=max(maxans,height[i]*(rightsmall[i]-leftsmall[i]+1));
    }
    return maxans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxa=0;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int area = f(heights);
            maxa=max(area,maxa);
        }
      return maxa;
    }
};