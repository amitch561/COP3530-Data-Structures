/*Albert Mitchell
* COP 3530
*/

#include<iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* newNode(int value) 
{
    BinaryTreeNode* node = new BinaryTreeNode;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
//QUESTION 9

int ComputeWeight(BinaryTreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftsubtree = ComputeWeight(root->left);
    int rightsubtree = ComputeWeight(root->right);

    return root->value + leftsubtree + rightsubtree;

}

void deleteTree(BinaryTreeNode* node)
{
    if (node == nullptr)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

bool IsComplete(BinaryTreeNode* root)
{
    if (root == nullptr) return true;
    queue<BinaryTreeNode*> q;
    q.push(root);
    bool leafneeded = false;
    while (!q.empty())
    {
        BinaryTreeNode* current = q.front();
        q.pop();
        if (current->left)
        {
            if (leafneeded) return false;
            q.push(current->left);
        }
        else
        {
            leafneeded = true;
        }
        if (leafneeded && current->right) return false;
        if (current->right) q.push(current->right);
    }
    return true;
}




    int main()
    {
        int weight;
        
        BinaryTreeNode* root = newNode(3);
        root->left = newNode(9);
        root->right = newNode(20);
        root->left->left = newNode(8);
        root->left->right = newNode(11);
        root->right->left = newNode(15);
        root->right->right = newNode(7);

        weight = ComputeWeight(root);
        cout << " Weight of tree: " << weight<<endl;
        cout << "Is the tree complete? " << (IsComplete(root) ? "Yes" : "No")<<endl;

        deleteTree(root);
                
        return 0;
    }
