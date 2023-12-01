bool f(Node *root , int left , int right){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL){
        if(right < left) return true;
        int rootRight = right-1;
        int rootLeft = left+1;
        if(rootRight >= left && right >= rootLeft) return false;
        return true;
    }
    bool l = f(root->left , left , root->data-1);
    if(l == true) return l;
    bool r = f(root->right , root->data +1 , right);
    return r;
}

bool isDeadEnd(Node *root)
{
    return f(root , 1 , 1e9);
}