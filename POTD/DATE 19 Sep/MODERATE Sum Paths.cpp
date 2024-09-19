int numOfPathsStartingHere(BinaryTreeNode<int> *root, int target) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if (root->data == target) {
        count++;
    }
    return count + numOfPathsStartingHere(root->left, target - root->data) +
           numOfPathsStartingHere(root->right, target - root->data);
}

int findSumPaths(BinaryTreeNode<int> *root, int target) {

    if (root == NULL) {
        return 0;
    }
    return numOfPathsStartingHere(root, target) + findSumPaths(root->left, target) +
           findSumPaths(root->right, target);
}
