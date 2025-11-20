class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& num1, vector<int>& num2, int k) {
        int n1=num1.size();
        int n2=num2.size();
        
        priority_queue<pair<int,pair<int,int>>> pq;
        // int s1=0,s2=0;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int sum=num1[i]+num2[j];
                
                if(pq.size()<k)
                {
                    pq.push({sum,{num1[i],num2[j]}});
                }
                else if(pq.top().first>sum)
                {
                    pq.pop();
                    pq.push({sum,{num1[i],num2[j]}});
                }
                else
                {
                    break;
                }
                // cout<<num1[i]<<" * "<<num2[j]<<" * ";
            }
        }
        while(pq.size()>k)
        {
            pq.pop();
        }
        int x=pq.size();
        // cout<<x<<" * ";
        vector<vector<int>> ans(x);
        for(int i=x-1;i>=0;i--)
        {
            ans[i].push_back(pq.top().second.first);
            ans[i].push_back(pq.top().second.second);
            pq.pop();
        }



        // while(s1<n1 && s2<n2)
        // {
        //     vector<int> f;
        //     f.push_back(num1[s1]);
        //     f.push_back(num2[s2]);
        //     ans.push_back(f);
        //     if(ans.size()>=k)
        //             return ans;
        //     if(num1[s1]<num2[s2])
        //     {
        //         int j=s2+1;
        //         while(s1+1<n1 && j<n2 && num1[s1]+num2[j]<=num1[s1+1]+num2[s2])
        //         {
        //             vector<int> tt;
        //             tt.push_back(num1[s1]);
        //             tt.push_back(num2[j]);
        //             // tt.push_back({num1[s1],num2[j]});
        //             ans.push_back(tt);
        //             if(ans.size()>=k)
        //             return ans;
        //             j++;
        //         }
        //         s1++;
        //     }
        //     else
        //     {
        //         int j=s1+1;
        //         while(s2+1<n2 && j<n2 && num2[s2]+num1[j]<=num2[s2+1]+num1[s1])
        //         {
        //             vector<int> tt;
        //             tt.push_back(num1[j]);
        //             tt.push_back(num2[s2]);
        //             // tt.push_back({num1[s2],num2[j]});
        //             ans.push_back(tt);
        //             if(ans.size()>=k)
        //             return ans;
        //             j++;
        //         }
        //         s2++;
        //     }
        // }
        return ans;

    }
};