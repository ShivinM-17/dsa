#include<iostream>
#include<queue>
using namespace std;
// seeing the binary tree from right side
//like wind will blow on which nodes if if blows rightways
/*         1
        2     3
      4  5   6  7
*/
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
//time complexity --> O(n)
void rightView(Node* root){
    if(root==NULL) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();

            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // right view
    rightView(root);
    return 0;
}