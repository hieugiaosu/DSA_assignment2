#include "ConcatStringTree.h"
// class Node
ConcatStringTree::Node::Node():length(0),leftLength(0),left(NULL),right(NULL),data(NULL),parents(){
    this->id = ConcatStringTree::ParentsTree::maxkey +1;
    ConcatStringTree::ParentsTree::maxkey++;
    parents.addNode(this);
}

ConcatStringTree::Node::Node(const char *s):length(0),leftLength(0),left(NULL),right(NULL),parents(){
    for (int i=0;s[i];i++) length++;
    this -> data = new char[length+1];
    for (int i=0;i<=length;i++) this->data[i]=s[i];
    this->id = ConcatStringTree::ParentsTree::maxkey +1;
    ConcatStringTree::ParentsTree::maxkey++;
    parents.addNode(this);
}
string ConcatStringTree::Node::info() const{
    stringstream ss;
    ss<<"(LL="<<this->leftLength<<",L="<<this->length;
    if (this->data == NULL) ss<<",<NULL>)";
        else ss<<",\""<<this->data<<"\")";
    string ans = ss.str();
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
    string ans ="ConcatStringTree[\"";
    toStringRec(p,ans);
    ans+="\"]";
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
    (this->root->parents).addNode(temp);
    (otherS.root->parents).addNode(temp);
    return ConcatStringTree(temp,temp->length);
}
ConcatStringTree ConcatStringTree::subString(int from, int to) const{
    if (from<0 || from >= size || to <=0 || to>size) throw out_of_range("Index of string is invalid!");
    if (from >= to) throw  logic_error("Invalid range!");
    Node * p = root;
    Node * rootNode = subStringRecursive(p,from,to);
    (rootNode->parents).addNode(rootNode);
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
        (temp->parents).deleteNode(temp);
        return temp;
    } 
    Node * temp = new Node;
    (temp->parents).deleteNode(temp);
    temp->length = to - from;
    if (node->leftLength < from) {
        temp -> right = subStringRecursive(node -> right,from - node->leftLength,to - node->leftLength);
        ((temp->right)->parents).addNode(temp);
    } else {
        if (node -> leftLength >= to){
            temp->leftLength = to - from;
            temp -> left = subStringRecursive(node -> left,from ,to);
            ((temp->left)->parents).addNode(temp);
        } else {
            temp -> leftLength = node ->leftLength - from;
            temp -> left = subStringRecursive(node->left,from,node ->leftLength);
            temp -> right = subStringRecursive(node->right,0,to - node->leftLength);
            ((temp->left)->parents).addNode(temp);
            ((temp->right)->parents).addNode(temp);
        }
    }
    return temp;
}

ConcatStringTree ConcatStringTree::reverse() const{
    Node *p = root;
    Node *rootNode = reverseRecursive(p);
    (rootNode->parents).addNode(rootNode);
    return ConcatStringTree(rootNode,this->size);
}

ConcatStringTree::Node* ConcatStringTree::reverseRecursive(Node * node) const{
    if (node == NULL) return NULL;
    Node * temp = new Node;
    (temp->parents).deleteNode(temp);
    int len = node ->length;
    if (node->data != NULL){
        temp -> length = len;
        temp -> data = new char[len+1];
        for (int i=0;node->data[i];i++){
            temp->data[len-1-i] = node -> data[i];
        }
        temp->data[len] = '\0';
        return temp;
    }
    temp ->length = len;
    if (node -> right == NULL) temp ->leftLength =0;
        else temp->leftLength = node ->right ->length;
    temp -> left = reverseRecursive(node -> right);
    temp -> right = reverseRecursive(node->left);
    if (temp->left) ((temp->left)->parents).addNode(temp);
    if (temp->right) ((temp->right)->parents).addNode(temp);
    return temp;
}

int ConcatStringTree::getParTreeSize(const string & query) const{
    Node *p = root;
    int n=query.size();
    for (int i=0;i<n;i++){
        if (query[i]=='l') p=p->left;
            else {
                if (query[i]=='r') p=p->right;
                    else throw runtime_error("Invalid character of query");
            }
        if (p==NULL) throw runtime_error("Invalid query: reaching NULL");
    }
    return (p->parents).size();
}

string ConcatStringTree::getParTreeStringPreOrder(const string & query) const{
    Node *p = root;
    int n=query.size();
    for (int i=0;i<n;i++){
        if (query[i]=='l') p=p->left;
            else {
                if (query[i]=='r') p=p->right;
                    else throw runtime_error("Invalid character of query");
            }
        if (p==NULL) throw runtime_error("Invalid query: reaching NULL");
    }
    return (p->parents).toStringPreOrder();
}

ConcatStringTree::~ConcatStringTree(){
    Node *temp = this->root;
    this->size = 0;
    this->root = NULL;
    (temp->parents).deleteNode(temp);
    deleteTree(temp);
}

void ConcatStringTree::deleteTree(Node *& node){
    if (node == NULL) return;
    if ((node->parents).size()!=0) return;
    if (node->left) (node->left)->parents.deleteNode(node);
    if (node->right) (node->right)->parents.deleteNode(node);
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
// ParentsTree
int ConcatStringTree::ParentsTree::maxkey = 0;
ConcatStringTree::ParentsTree::ParentsTree():root(NULL),treeSize(0){}

void ConcatStringTree::ParentsTree::addNode(Node* parent){
    treeSize++;
    if (maxkey>maxNode) throw overflow_error("Id is overflow!");
    if (this->root == NULL){
        root = new TreeNode(parent);
        return;
    } else {
        root=addNodeRec(root,parent);
    }
}
int ConcatStringTree::ParentsTree::size() const{
    return treeSize;
}

string ConcatStringTree::ParentsTree::toStringPreOrder() const{
    if (this->root == NULL) return "ParentsTree[]";
    string ans="ParentsTree[";
    stringstream ss;
    ss<<"(id="<<root->data->id<<")";
    string temp = ss.str();
    ans+=temp;
    TreeNode *p = root;
    preOrderTravelsal(p->left,ans);
    preOrderTravelsal(p->right,ans);
    ans+="]";
    return ans;
}
void ConcatStringTree::ParentsTree::preOrderTravelsal(TreeNode *&p, string&ans) const{
    if (p==NULL) return;
    stringstream ss;
    ss<<";(id="<<p->data->id<<")";
    string temp = ss.str();
    ans+=temp;
    preOrderTravelsal(p->left,ans);
    preOrderTravelsal(p->right,ans);
}
ConcatStringTree::ParentsTree::TreeNode* ConcatStringTree::ParentsTree::addNodeRec(TreeNode *p, Node * parent){
    if (p==NULL) return NULL;
    if (parent->id < p->data->id){
        if (p->left==NULL) {
            p->left = new TreeNode(parent);
        } else {
            p->left = addNodeRec(p->left,parent);
        }
    } else {
        if (p->right==NULL) {
            p->right = new TreeNode(parent);
        } else {
            p->right = addNodeRec(p->right,parent);
        }
    }
    p->updateHeight();
    return ensureBalance(p);
}

ConcatStringTree::ParentsTree::TreeNode * ConcatStringTree::ParentsTree::ensureBalance(TreeNode *p){
    if (p==NULL) return NULL;
    int leftheight =(p->left==NULL)?0:p->left->height;
    int rightheight = (p->right == NULL)?0:p->right->height;
    if (leftheight - rightheight <= 1 && leftheight-rightheight>=-1) return p;
    if (leftheight - rightheight>1){
        int LL = (p->left->left==NULL)?0:p->left->left->height; //left of left
        int LR = (p->left->right==NULL)?0:p->left->right->height; // right of left
        if (LL>LR) { // case left of left
            TreeNode *temp = p->left; //rotate right
            p->left = temp -> right;
            temp->right = p;
            p->updateHeight();
            return temp;
        } else { // case right of left
            TreeNode *temp = p->left;  // rotate left
            p->left = temp->right;
            temp -> right = p->left->left;
            p->left ->left = temp;
            p->left->updateHeight();
            temp = p->left; // rotate right
            p->left = temp -> right;
            temp->right = p;
            p->updateHeight();
            return temp;
        }
    } else {
        int RR = (p->right->right==NULL)?0:p->right->right->height; //right of right
        int RL = (p->right->left==NULL)?0:p->right->left->height; // left of right
        if (RR>RL){ // case right of right
            TreeNode *temp = p->right; // rotate left
            p->right = temp -> left;
            temp-> left = p;
            p->updateHeight();
            return temp;
        } else { // case left of right
            TreeNode * temp = p->right; // rotate right
            p->right = temp -> left;
            temp -> left = p->right->right;
            p->right->right = temp;
            p->right->updateHeight();
            temp = p->right; // rotate left
            p->right = temp -> left;
            temp-> left = p;
            p->updateHeight();
            return temp;
        }
    }
}

void ConcatStringTree::ParentsTree::deleteNode(Node* parent){
    TreeNode *p = root;
    root = deleteRec(root,parent->id);
}


ConcatStringTree::ParentsTree::TreeNode* ConcatStringTree::ParentsTree::deleteRec(TreeNode*p,int key){
    if (p==NULL) return NULL;
    if (p->data->id == key){
        this->treeSize --;
        if (p->left==NULL){
            TreeNode* temp = p;
            p = p->right;
            delete temp;
        } else if (p->right==NULL){
            TreeNode* temp = p;
            p = p->left;
            delete temp;
        } else {
            TreeNode* temp = p->left;
            while (temp->right) temp = temp->right;
            p->data = temp->data;
            p->left = deleteRec(p->left,temp->data->id);
        }
    } else {
        if (key<p->data->id) p->left = deleteRec(p->left,key);
            else p->right = deleteRec(p->right,key);
    }
    if (p!=NULL) p->updateHeight();
    return ensureBalance(p);
}
void ConcatStringTree::ParentsTree::deleteTree(TreeNode *&p){
    if (p == NULL) return;
    deleteTree(p->left);
    deleteTree(p->right);
    delete p;
}

ConcatStringTree::ParentsTree::~ParentsTree(){
    TreeNode *temp = root;
    this->root = NULL;
    this->treeSize=0;
    deleteTree(temp);
}
// TreeNode
ConcatStringTree::ParentsTree::TreeNode::TreeNode(Node *data):height(1),left(NULL),right(NULL),data(data){}
void ConcatStringTree::ParentsTree::TreeNode::updateHeight(){
    int leftHeight = (left == NULL)?0:left->height;
    int rightHeight = (right==NULL)?0:right->height;
    height = (leftHeight>rightHeight)?leftHeight+1:rightHeight+1;
}

// LitStringHash
ReducedConcatStringTree::LitStringHash::LitStringHash(const HashConfig & hashConfig){
    this->count = 0;
    this->last = -1;
    this->p = hashConfig.p;
    this->c1 = hashConfig.c1;
    this->c2 = hashConfig.c2;
    this->lambda = hashConfig.lambda;
    this->alpha = hashConfig.lambda;
    this->initSize = hashConfig.initSize;
    this->hashTable = new Node * [initSize];
    for (int i=0;i<initSize;i++) hashTable[i] = NULL;
}
int ReducedConcatStringTree::LitStringHash::getLastInsertedIndex() const{
    return last;
}

string ReducedConcatStringTree::LitStringHash::toString() const{
    string ans ="LitStringHash[";
    stringstream ss;
    if (hashTable[0]==NULL) ss<<"()";
        else {
            ss<<"(litS=\""<<hashTable[0]->data<<"\")";
        }
    for (int i=1;i<initSize;i++) {
        if (hashTable[i]==NULL) ss<<";()";
        else {
            ss<<";(litS=\""<<hashTable[i]->data<<"\")";
        }
    }
    ans += (ss.str());
    ans+= ']';
    return ans;
}

int ReducedConcatStringTree::LitStringHash::hashFunction(const char *key){
    int temp =1;
    int ans =0;
    for (int i=0;key[i];i++){
        ans = (ans + (int(key[i])%initSize)*(temp%initSize))%initSize;
        temp = ((temp%initSize)*(this->p%initSize))%initSize;
    }
    return ans%initSize;
}

int ReducedConcatStringTree::LitStringHash::findFunction(int h, int i){
    int ans;
    double help = c1 + c2*i*1.0;
    double temp = help - int(help);
    if (temp*i > -1 && temp*i<1){
        ans = (h%initSize + ((i%initSize)*(int(help)%initSize))%initSize)%initSize;
    } else {
        ans = (h%initSize + ((i%initSize)*(int(help)%initSize))%initSize + int(i*temp)%initSize)%initSize;
    }
    return ans;
}

ReducedConcatStringTree::Node*& ReducedConcatStringTree::LitStringHash::at(const char *key){
    int idx = hashFunction(key);
    bool compare = true;
    if (hashTable[idx] == NULL) return hashTable[idx];
        else {
            for (int i=0;key[i] || hashTable[idx]->data[i];i++) 
                if (key[i]!=hashTable[idx]->data[i]) {
                    compare = false;
                    break;
                }
            if (compare) return  hashTable[idx];
        }
    
}