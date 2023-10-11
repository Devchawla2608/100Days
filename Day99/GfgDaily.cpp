    
    pair<bool , int> height(struct Node* node){
        if(node == NULL) return {true , 0};
        if(node->left == NULL && node->right == NULL) return {true , 1};
        pair<bool , int> left = height(node->left);
        pair<bool , int> right = height(node->right);
        if(left.first == true && right.first == true){
            if(abs(left.second - right.second)<=1) return {true , max(left.second , right.second)+1};
        }
        return {false, max(left.second , right.second)+1};
    }
    
    bool isBalanced(Node *root)
    {
        pair<bool , int> temp = height(root);
        return temp.first;
    }