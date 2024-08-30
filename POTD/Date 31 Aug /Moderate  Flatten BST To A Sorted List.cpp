void inorderTraversal(TreeNode<int> *root, vector<TreeNode<int>*> &v){

    if(root == NULL){

        return;

    }

    //L

    if(root -> left!= NULL){

        inorderTraversal(root -> left,v);

    }

    

    //N

    v.push_back(root);

    //R

    if(root -> right !=NULL){

        inorderTraversal(root -> right,v);

    }

}

TreeNode<int>* flatten(TreeNode<int>* root)

{

    vector<TreeNode<int>*> v;

    inorderTraversal(root, v);

    TreeNode<int>* head = v[0];

    for(int i=0; i< v.size()-1; i++){

        v[i] -> left = NULL;

        v[i] -> right = v[i+1];

    }

    v[v.size()-1] -> left = NULL;

    v[v.size()-1] -> right = NULL;

    return head;

}

