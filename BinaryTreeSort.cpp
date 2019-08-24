#include <iostream>
using namespace std;

struct BST
{
    int number; //保存数组元素的值
    struct BST *left;
    struct BST *right;
};

void insertBST(BST **tree, int v)
{
    if (*tree == NULL)
    {
        *tree = new BST;
        (*tree)->left = (*tree)->right = NULL;
        (*tree)->number = v;
        return;
    }
    if (v < (*tree)->number)
        insertBST(&((*tree)->left), v);
    else
        insertBST(&((*tree)->right), v);
}

void printBSTResult(BST *tree)
{
    if (tree == NULL)
        return;
    if (tree->left != NULL)
        printResult(tree->left);
    cout << tree->number << "  ";
    if (tree->right != NULL)
        printResult(tree->right);
}

void createBST(BST **tree, int a[], int n)
{
    *tree = NULL;
    for (int i = 0; i < n; i++)
        insertBST(tree, a[i]);
}

int main()
{
    int arr[] = {7, 8, 8, 9, 5, 16, 5, 3, 56, 21, 34, 15, 42};
    int n = sizeof(arr) / sizeof(int);
    BST *root;
    createBST(&root, arr, n);
    printBSTResult(root);
}
