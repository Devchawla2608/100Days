// Diagonal Traversal of Binary Tree
// Given a Binary Tree, print the diagonal traversal of the binary tree.
// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 
vector<int> diagonal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    vector<int> v;
    while(q.size()){
            Node* front = q.front();
            q.pop();
            v.push_back(front->data);
            if(front->left != NULL){
                    q.push(front->left);
                } 
            while(front->right != NULL){
                front = front->right;
                  if(front->left != NULL){
                    q.push(front->left);
                } 
                v.push_back(front->data);
                }
        }
    return v;
    
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)