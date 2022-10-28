#include "ConcatStringTree.h"
// class Node
ConcatStringTree::Node::Node():length(0),leftLength(0),left(NULL),right(NULL),data(NULL){}

ConcatStringTree::Node::Node(const char *s):length(0),leftLength(0),left(NULL),right(NULL){
    for (int i=0;s[i];i++) length++;
    this -> data = new char[length+1];
    for (int i=0;i<=length;i++) this->data[i]=s[i];
}
string ConcatStringTree::Node::info() const{
    stringstream ss;
    ss<<"(LL="<<this->leftLength<<",L="<<this->length;
    if (this->data == NULL) ss<<",<NULL>)";
        else ss<<','<<this->data<<')';
    string ans;
    ss>>ans;
    return ans;
}
ConcatStringTree::Node::~Node(){
    if (this->data != NULL) delete[] this->data;
}
// class ConcatStringTree
ConcatStringTree::ConcatStringTree(Node *root,int size):root(root),size(size){}
ConcatStringTree::ConcatStringTree(const char *s){
    this->root = new Node(s);
    this->size = this->root->length;
}

int ConcatStringTree::length() const{
    return this->size;
}

char ConcatStringTree::get(int index) {
    if (index<0 || index>= size) throw out_of_range("Index of string is invalid!");
    Node *p = this->root;
    while (p->data == NULL){
        if (index < p->leftLength){
            p = p->left;
        } else {
            index -= p->leftLength;
            p=p->right;
        }
    }
    return p->data[index];
}

int ConcatStringTree::indexOf(char c){
    if (this->size == 0) return -1;
    Node *p = root;
    return indexOf(c,p);
}

int ConcatStringTree::indexOf(char c, Node *p){
    if (p == NULL) return -1;
    if (p->length == 0) return -1;
    if (p->data != NULL) {
        for (int i=0; p->data[i];i++) 
            if (p->data[i]==c) return i;
        return -1;
    }
    int index = indexOf(c,p->left);
    return (index != -1)?index:p->leftLength+indexOf(c,p->right);
}

string ConcatStringTree::toStringPreOrder() const{
    string ans="ConcatStringTree[";
    Node *p = root;
    preoderTravelsal(p,ans);
    ans+=']';
    return ans;
}

void ConcatStringTree::preoderTravelsal(Node*&p,string &ans) const{
    if (p==NULL) return;
    ans += p->info();
    if (p->left){
        ans +=';';
        preoderTravelsal(p->left,ans);
    }
    if (p->right){
        ans+=';';
        preoderTravelsal(p->right,ans);
    }
}

string ConcatStringTree::toString() const{
    Node *p = root;
    string ans ="";
    toStringRec(p,ans);
    return ans;
}

void ConcatStringTree::toStringRec(Node *&p,string &ans) const{
    if (p==NULL) return;
    if (p->data != NULL){
        for (int i=0;p->data[i];i++) ans += p->data[i];
        return;
    }
    toStringRec(p->left,ans);
    toStringRec(p->right,ans);
}
ConcatStringTree ConcatStringTree::concat(const ConcatStringTree & otherS) const{
    Node * temp = new Node;
    temp->left = this->root;
    temp->right = otherS.root;
    temp->leftLength = this->size;
    temp->length = this->size + otherS.size;
    return ConcatStringTree(temp,temp->length);
}
ConcatStringTree ConcatStringTree::subString(int from, int to) const{
    if (from<0 || from >= size || to <=0 || to>size) throw out_of_range("Index of string is invalid!");
    if (from >= to) throw  logic_error("Invalid range!");
    Node * p = root;
    Node * rootNode = subStringRecursive(p,from,to);
    return ConcatStringTree(rootNode,to - from);
}
ConcatStringTree::Node* ConcatStringTree::subStringRecursive(Node * node,int from, int to) const{
    if (node == NULL) return NULL;
    if (node->data != NULL){
        Node * temp = new Node;
        temp->length = to - from;
        temp->data = new char[temp->length+1];
        for (int i=from;i < to;i++){
            temp->data[i-from] = node ->data[i];
        }
        temp->data[to - from] = '\0';
        return temp;
    } 
    Node * temp = new Node;
    temp->length = to - from;
    if (node->leftLength < from) {
        temp -> right = subStringRecursive(node -> right,from - node->leftLength,to - node->leftLength);
    } else {
        if (node -> leftLength >= to){
            temp->leftLength = to - from;
            temp -> left = subStringRecursive(node -> left,from ,to);
        } else {
            temp -> leftLength = node ->leftLength - from;
            temp -> left = subStringRecursive(node->left,from,node ->leftLength);
            temp -> right = subStringRecursive(node->right,0,to - node->leftLength);
        }
    }
    return temp;
}