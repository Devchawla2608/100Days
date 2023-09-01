void printCorner(Node *root)
{
    
    if(root == NULL) return;
    if(root ->left == NULL && root->right == NULL){
        cout<<root->data<<endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(q.size() != 0){
        int size = q.size();
        int i = size;
        while(size--){
            Node* root = q.front();
            q.pop();
            if(size == 0 || i == size+1){
                cout<<root->data<<" ";
            }
            i++;
            if(root->left != NULL) q.push(root->left);
            if(root->right != NULL) q.push(root->right);
        }
    }
}