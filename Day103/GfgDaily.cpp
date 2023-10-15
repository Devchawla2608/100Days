void solve(Node* root , vector<int> &v){
    if(root == NULL) return;
    solve(root->left , v);
    v.push_back(root->data);
    solve(root->right , v);
    return ;
}

Node* solve2(vector<int> &v , int start , int end){
    if(start > end){
        return NULL;
    }
    int index = (start+end)/2;
    int element = v[index];
    Node* newNode = new Node(element);
    Node *left = solve2( v , start , index-1);
    Node* right = solve2( v , index+1 , end);
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* buildBalancedTree(Node* root)
{
	if(root == NULL){
	    return NULL;
	}
	vector<int> v;
	solve(root , v);
	sort(v.begin() , v.end());
    return solve2( v , 0 , v.size()-1);
}