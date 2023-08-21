typedef pair<int , pair<int , pair<int , bool>>> pppi;

class Solution{
    public:
    
    
    bool checkBst(pppi left , pppi right , Node* root){
        if(left.second.second.second == false || right.second.second.second == false) return false;
        if(root->data <= left.first) return false;
        if(root->data >= right.second.first) return false;
        return true;
    }
    
    pppi f(Node* root){
        
        if(root == NULL) return {INT_MIN , { 1e9 , {0 , true}}};
        
        if(root->left == NULL && root->right == NULL) {
            return {root->data , {root->data , {1 , true}}};
        }
        pppi left = f(root->left);
        pppi right = f(root->right);
        bool tell = checkBst(left , right , root);
        if(tell == true){
            int mn = 1e9;
            int mx = INT_MIN;
            if(left.second.first == 1e9) mn = root->data;
            else mn = left.second.first;
            if(right.first == INT_MIN) mx = root->data;
            else mx = right.first;  
            int size = left.second.second.first + right.second.second.first + 1;
            return {mx , {mn , { size,  true}}};
        }
        int size = max(left.second.second.first , right.second.second.first);
        return {INT_MIN , { 1e9 , { size , false}}};
    }
    int largestBst(Node *root)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        pppi pr = f(root);
        return pr.second.second.first;
    }