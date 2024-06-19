#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int x){
        key=x;
        left=right=NULL;
    }
};

//searching
bool search(Node *root,int key){
    if(root==NULL){
        return false;
    }
    else if(root->key==key){
        return true;
    }
    else if(root->key>key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

//insert
Node *insert(Node *root,int x){
    if(root==NULL){
        return new Node(x);
    }
    else if(root->key<x){
        root->right=insert(root->right,x);
    }
    else{
        root->left=insert(root->left,x);
    }
    return root;
}

//deleteing element
Node *getSucc(Node *curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

Node *delNode(Node *root,int x){
    if(root == NULL){
        return root;
    }
    else if(root->key>x){
        root->left=delNode(root->left,x);
    }
    else if(root->key<x){
        root->right=delNode(root->right,x);
    }
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ=getSucc(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
}

//tree traversal
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
} 

int main(){
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(12);
	root->right->right=new Node(18);
	int x=15;
	
	root=delNode(root,x);
	inorder(root);
}