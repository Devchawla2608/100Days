class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void solve(Node* root , vector<int> &v){
        if(root == NULL){
            return;
        }
        solve(root->left , v);
        v.push_back(root->data);
        solve(root->right , v);
    }
    
    Node* solve2(Node* root , vector<int> &v){
        if(root == NULL){
            return root;
        }
        if(root->left == NULL && root->right == NULL){
            root->data = v.front();
            v.erase(v.begin() , v.begin() + 1);
            return root;
        }
        Node* left = solve2(root->left , v);
        root->data = v.front();
        v.erase(v.begin() , v.begin() + 1);
        Node* right = solve2(root->right , v);
        return root;
    }
    Node *binaryTreeToBST (Node *root)
    {
     if(root == NULL){
         return NULL;
     }
      vector<int> v;
      solve(root , v);
      sort(v.begin() , v.end());
      return solve2(root , v);
    }
};