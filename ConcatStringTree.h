#ifndef __CONCAT_STRING_TREE_H__
#define __CONCAT_STRING_TREE_H__

#include "main.h"

class ConcatStringTree {
public:
    class Node; //forward declaration
    class ParentsTree; //forward declaration
public:
    Node *root;
    int size;
private:
    int indexOf(char c, Node* p);
    void preoderTravelsal(Node*& p,string &ans) const;
    void toStringRec(Node *&p, string &ans) const;
    Node * subStringRecursive(Node * node,int from, int to) const;
    Node * reverseRecursive(Node *node) const;
    void updateParent(Node *&p, Node *node);
    void deleteParent(Node *p, Node *node);
public:
    ConcatStringTree(Node *root,int size);
    ConcatStringTree(const char * s);
    int length() const;
    char get(int index);
    int indexOf(char c);
    string toStringPreOrder() const;
    string toString() const;
    ConcatStringTree concat(const ConcatStringTree & otherS) const;
    ConcatStringTree subString(int from, int to) const;
    ConcatStringTree reverse() const;
    ~ConcatStringTree();

    int getParTreeSize(const string & query) const;
    string getParTreeStringPreOrder(const string & query) const;
public:
    class ParentsTree{
        public:
        class TreeNode;

        public:
        static const int maxNode = 10000000;
        TreeNode *root;
        int maxkey;
        int treeSize;

        private:
        TreeNode* addNodeRec(TreeNode *p, Node *parent, int key);
        TreeNode* ensureBalance(TreeNode *p);
        void preOrderTravelsal(TreeNode *&p, string&ans) const;
        int find(Node* parrent,TreeNode *node) const;
        TreeNode* deleteRec(TreeNode*p,int key);

        public:
        ParentsTree();
        int size() const;
        string toStringPreOrder() const;
        void addNode(Node *parrent);
        void deleteNode(Node *parrent);
        void deleteTree(TreeNode *&p);
        ~ParentsTree();
        public:
        class TreeNode{
            public:
            int key;
            int height;
            Node * data;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int key, Node* data);
            void updateHeight();
        };
    };
    class Node{
        public:
        int leftLength;
        int length;
        char *data;
        ParentsTree parents;
        Node *left;
        Node *right;
        bool deleteStatus = false;
        Node();
        Node(const char *s);
        string info() const;
        ~Node();
    };
};

class ReducedConcatStringTree; // forward declaration

class HashConfig {
private:
    int p;
    double c1, c2;
    double lambda;
    double alpha;
    int initSize;

    friend class ReducedConcatStringTree;
};

class ReducedConcatStringTree /* */ {

public:
    class LitStringHash {
    public:
        LitStringHash(const HashConfig & hashConfig);
        int getLastInsertedIndex() const;
        string toString() const;
    };

public:
    static LitStringHash litStringHash;
};

#endif // __CONCAT_STRING_TREE_H__
