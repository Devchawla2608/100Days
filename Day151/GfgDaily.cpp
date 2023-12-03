    void Inorder(Node* root , unordered_map<int , int> &ourmap , int &count , int x){
        if(root == NULL){
            return;
        }
        Inorder(root->left , ourmap , count , x);
        if(ourmap[x-root->data] >0){
            count = count + ourmap[x- root->data];
            ourmap[x-root->data] = 0;
        }
        Inorder(root->right , ourmap , count , x);
    }

    void solve(Node* root , unordered_map<int , int> &ourmap){
        if(root == NULL){
            return;
        }
        ourmap[root->data]++;
        solve(root->left , ourmap);
        solve(root->right , ourmap);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int,int> ourmap;
        solve(root2 , ourmap);
        int count = 0;
        Inorder(root1 , ourmap , count , x);
         return count;
    }