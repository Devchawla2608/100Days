        bool findNode(Node* root , int key){
            if(root == NULL) return false;
            if(root->data == key) return true;
            bool find = false;
            if(key > root->data){
                find = findNode(root->right , key);
                return find;
            }
            find = findNode(root->left , key);
            return find;
        }
        
        Node* insertNode(Node* root , int key){
            if(root == NULL){Node* newNode = new Node(key); return newNode;}
            Node* node;
            if(key > root->data) {node = insertNode(root->right , key); root->right = node;}
            else{  node = insertNode(root->left , key); root->left = node;} 
            return root;
        }
        Node* insert(Node* node, int data) {
            
            if(node == NULL){
                Node* newNode = new Node(data);
                return newNode;
            }
            
            bool find = findNode(node , data);
            
            if(find == true) return node;
            node = insertNode(node , data);
            return node;
        }