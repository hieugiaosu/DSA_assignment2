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
protected:
    int indexOf(char c, Node* p);
    void preoderTravelsal(Node*& p,string &ans) const;
    void toStringRec(Node *&p, string &ans) const;
    Node * subStringRecursive(Node * node,int from, int to) const;
    Node * reverseRecursive(Node *node) const;
    void deleteTree(Node *&node);
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
        friend class Node;
        public:
        static const int maxNode = 10000000;
        TreeNode *root;
        static int maxkey;
        int treeSize;

        protected:
        TreeNode* addNodeRec(TreeNode *p, Node *parent);
        TreeNode* ensureBalance(TreeNode *p);
        void preOrderTravelsal(TreeNode *&p, string&ans) const;
        TreeNode* deleteRec(TreeNode*p,int key);

        public:
        ParentsTree();
        int size() const;
        string toStringPreOrder() const;
        void addNode(Node *parrent);
        void deleteNode(Node *parent);
        void deleteTree(TreeNode *&p);
        ~ParentsTree();
        public:
        class TreeNode{
            public:
            int height;
            Node * data;
            TreeNode *left;
            TreeNode *right;
            TreeNode( Node* data);
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
        int id;
        Node();
        Node(const char *s);
        string info() const;
        ~Node();
    };
};

class ReducedConcatStringTree; // forward declaration
class LitStringHash;
class HashConfig {
private:
    int p;
    double c1, c2;
    double lambda;
    double alpha;
    int initSize;

    friend class ReducedConcatStringTree;
    friend class LitStringHash;
};
class LitStringHash {
    public:
        class litString;
        friend class ReducedConcatStringTree;
        enum Status {EMPTY,NON_EMPTY,DELETED};
    public:
        int p;
        double c1,c2;
        double lambda;
        double alpha;
        int initSize;
        int count;
        int last;
        litString ** hashTable;
        LitStringHash(const HashConfig & hashConfig);
        ~LitStringHash();
    private:
        int hashFunction(const char *s);
        int findFunction(int h, int i);
        void rehashing();
    public:
        string toString() const;
        int getLastInsertedIndex() const;
        litString*& push(const char *s);
        int find(const char *s);
        void pop(const char *s);
        // litString*& operator[](const char *s);
    public:
    class litString{
        public:
        ReducedConcatStringTree::Node* node;
        Status status;
        int count;
        litString();
        string info() const;
        ~litString();
    };
};
class ReducedConcatStringTree : public ConcatStringTree {
    public:
        LitStringHash * litStringHash;
        ReducedConcatStringTree(const char * s, LitStringHash * litStringHash);
        ReducedConcatStringTree(Node * root,int size,LitStringHash * litStringHash = NULL);
        ~ReducedConcatStringTree();
    protected:
        Node * subStringRecursive(Node * node,int from, int to) const;
        Node * reverseRecursive(Node *node) const;
        void deleteTree(Node *&node);
    public:
        ReducedConcatStringTree concat(const ReducedConcatStringTree  & otherS) const;
        ReducedConcatStringTree subString(int from, int to) const;
        ReducedConcatStringTree reverse() const;
};

#endif // __CONCAT_STRING_TREE_H__