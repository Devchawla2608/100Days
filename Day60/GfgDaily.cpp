    int getCount(Node *root, int k)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        queue<Node*> q;
        q.push(root);
        int i = 0;
        int cnt = 0;
        while(q.size() != 0){
            int size = q.size();
            i++;
            while(size--){
                Node* node = q.front();
                q.pop();
                if(k ==0) return cnt;
                if(node->left == NULL && node->right == NULL && k>= i){
                    k = k-i;
                    cnt++;
                }
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        return cnt;
    }