typedef long long ll;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll , ll>>> pq;
        ll sumi = 0;
        ll maxi = 1e18;
        for(ll i = 0; i<nums.size() ; i++){
            sumi += (ll)nums[i];
            if(sumi >= k)
            {
                maxi = min(maxi , i+1);
            }
            while(!pq.empty() && (sumi - pq.top().first >= k))
            {
                auto &p = (pq.top());
                maxi = min(maxi,i-p.second);
                pq.pop();
            }
            pq.push({sumi , i});
        }
        if(maxi == 1e18)
        {
            return -1;
        }
        else{
            return maxi;
        }
    }
};