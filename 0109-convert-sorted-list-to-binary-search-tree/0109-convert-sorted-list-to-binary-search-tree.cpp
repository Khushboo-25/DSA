/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
       if(nums.size()==0)
       return NULL;
        int n=nums.size();
        int m=n/2;
        TreeNode* root=new TreeNode(nums[m]);
        TreeNode* tp=root;
        vector<int>right;
        for(int i=m+1;i<n;i++)
        right.push_back(nums[i]);
        vector<int>left;
        for(int i=0;i<=m-1;i++)
        left.push_back(nums[i]);
        if(right.size()>0)
        tp->right=sortedArrayToBST(right);
    if(left.size()>0)
        tp->left=sortedArrayToBST(left);
            
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        while(head)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        return sortedArrayToBST(nums);
    }
};