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

    void findInorder( unordered_map<int , int> &mp , TreeNode* root){
        if(root == NULL) return;
        if(root->left != NULL) findInorder(mp , root->left);
        mp[root->val]++;
        if(root->right != NULL) findInorder(mp , root->right);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int , int> mp;
        findInorder(mp , root);
        int mx = INT_MIN;
        vector<int> ans;
        for(auto it : mp){
            mx = max(mx , it.second);
        }
       for(auto it : mp){
            if(it.second == mx){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};