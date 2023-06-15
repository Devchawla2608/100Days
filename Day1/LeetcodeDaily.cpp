    
// 1161. Maximum Level Sum of a Binary Tree
// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        int ans = INT_MIN;
        int resultLevel = 0; 
        while(q.size() != 0){
            int x = q.size();
            l++;
            int sum = 0;
            while(x--){
                TreeNode* top = q.front();
                q.pop();
                if(top == NULL) continue;
                sum = sum + top->val;
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
            if(sum > ans){
                ans = sum;
                resultLevel = l;
            }
        }
        return resultLevel;
    }