class Solution
{
    public:
    
     void findPreSuc(Node* root, Node*& pre, Node*& suc, int k)
    {
        pre=NULL;
        suc=NULL;
        while( root!=NULL && root->key!=k){
            if(root->key > k){
                suc=root;
                root=root->left;
            }
            else{
                pre=root;
                root=root->right;
            }
        }
        if(root==NULL) return;
        else{
            Node* temp1=root->left;
            while(temp1!=NULL){
                pre=temp1;
                temp1=temp1->right;
            }
            Node* tempr=root->right;
            while(tempr!=NULL){
                suc=tempr;
                tempr=tempr->left;
            }
        }
    }
};