    void f(Node* root , int x , int &save){
        if(root == NULL) return ;
        if(root->left != NULL) f(root->left , x , save);
        if(root->data <= x) save = max(save , root->data);
        if(root->right != NULL) f(root->right , x , save);
    }

    int floor(Node* root, int x) {
        int save = -1;
        f(root , x , save);
        return save;
    }