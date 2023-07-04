//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/binary-search-tree-lowest-common-ancestor
Node *lca(Node *root, int v1, int v2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == v1)
    {
        return root;
    }
    if (root->data == v2)
    {
        return root;
    }
    Node *left = lca(root->left, v1, v2);
    Node *right = lca(root->right, v1, v2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    else if (left != NULL)
    {
        return left;
    }
    else if (right != NULL)
    {
        return right;
    }
    return NULL;
}