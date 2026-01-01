class Solution {
public:
class Node{
    public: 
    long long val;
    Node* next;
    Node(int d)
    {
        this->val=d;
        this->next=NULL;
    }
};
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        Node* head=new Node(nums[n-1]);
        Node* tp=head;
        for(int i=n-2;i>=0;i--)
        {
            
            if(tp->val>=nums[i])
            {
                tp->val+=nums[i];
            }
            else
            {
                tp->next=new Node(nums[i]);
                tp=tp->next;
            }
        }
        long long ans=INT_MIN;
        while(head)
        {
            ans=max(ans,head->val);
            head=head->next;
        }
        return ans;
    }
};