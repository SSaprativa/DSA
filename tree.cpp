#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

//Tree Traversal
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

void levelorder(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false){
        Node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

//height
int height(Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        return max(height(root->left),height(root->right))+1;
    }
}

//Node at distance k
void printNodeatDistanceK(Node *root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->key<<" ";
    }
    else{
        printNodeatDistanceK(root->left,k-1);
        printNodeatDistanceK(root->right,k-1);
    }
}

//size of a tree
int getSize(Node *root){
    if(root==NULL){
        return 0;
    }
    else{
        return 1+getSize(root->left)+getSize(root->right);
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    cout<<getSize(root)<<endl;
}