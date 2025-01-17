/*Two trees are identical when they have same data and arrangement of data is also same. To identify if two trees are identical,
 we need to traverse both trees simultaneously, and while traversing we need to compare data and children of the trees.*/

#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class Node{
    public:
    Node* left;
    Node* right;
    int key;
    Node(int val){
        this->key=val;
        this->left=NULL;
        this->right=NULL;

    }
};
bool isidentical(Node * root1 , Node * root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2 !=NULL){
        return false;
    }
    if(root1 != NULL && root2==NULL){
        return false;
    }
    bool left=isidentical(root1->left,root2->left);
    bool right=isidentical(root1->right,root2->right);
    bool value=((root1->key)==(root2->key));
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }


}