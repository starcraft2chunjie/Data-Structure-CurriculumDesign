//
// Created by 唐艺峰 on 2017/12/12.
//

#ifndef STRUCTUREEXPRUNITTEST_BINARY_TREE_H
#define STRUCTUREEXPRUNITTEST_BINARY_TREE_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

/* A sample structure of the tree in order to fit the function Root()
 *                head
 *              /      \
 *            root     NULL
 *          /      \
 *       node1    node2
 *      /    \    /   \
 *    ...   ...  ...  ...
 */

typedef struct TreeNode{
    int index;              // index for each node
    int value;              // value (you can set it the same with its index at the beginning)
    struct TreeNode * leftChild;   // pointer to the left child
    struct TreeNode * rightChild;  // pointer to the right child
}TreeNode;

typedef struct QNode{
    TreeNode * data;
    struct QNode *next;
}QNode, * QueuePtr;


typedef struct {
    int location;
    QNode * front;
    QNode * rear;
}LinkQueue;

int InitQueue(LinkQueue *Q);
int EnQueue(LinkQueue *Q, TreeNode *e);
int UpdateKey(TreeNode *head, LinkQueue *Q, int index);
TreeNode  * Dequeue(LinkQueue *Q);
/*
 * @Name InitBiTree
 * @Args *head is the head of the tree
 * @Return Success or Failure
 */
int InitBiTree(TreeNode * head);

/*
 * @Name DestroyBiTree
 * @Args *head is the head of the tree
 * @Return Success or Failure
 * @Tips Please remember to free all the nodes of the tree not only the head or root nodes
 */
int DestroyBiTree(TreeNode * head);

/*
 * @Name CreateBiTree
 * @Args *head is the head of the tree
 *       *definition is an array of indexes or special symbols (-1 in the example) to
 *              describe the structure of the tree
 *              e.g. 1 2 3 -1 -1 -1 4 5 6
 *       lengthOfDef is the length of the definition array
 * @Return Success or Failure
 */
int CreateBiTree1(TreeNode * head, int * definition, int lengthOfDef, int index);
int CreateBiTree(TreeNode * head, int * definition, int lengthOfDef, int index, LinkQueue *Q);

/*
 * @Name CreateBiTree
 * @Args *head is the head of the tree
 *       *definition1 is an array of indexes which are in the pre order
 *              e.g. 1 2 4 5 6 7 3
 *       *definition2 is an array of indexes which are in the in order
 *              e.g. 4 5 2 7 6 1 3
 *       lengthOfDef is the length of the definition array
 * @Return Success or Failure
 */
// int CreateBiTree(TreeNode * head, int * definition1, int * definition2, int lengthOfDef);

/*
 * @Name ClearBiTree
 * @Args *head is the head of the tree
 * @Return Success or Failure
 * @Tips Please remember to free all the nodes of the tree not only the root node
 */
int true_lengthOfDef(int *definition, int lengthOfDef);
int ClearBiTree(TreeNode * head);

/*
 * @Name BiTreeEmpty
 * @Args *head is the head of the tree
 * @Return True or False
 */
int BiTreeEmpty(TreeNode * head);

/*
 * @Name BiTreeDepth
 * @Args *head is the head of the tree
 * @Return depth of the tree
 */
int BiTreeDepth(TreeNode * head);

/*
 * @Name Root
 * @Args *head is the head of the tree
 * @Return the pointer to the root node
 */
TreeNode * Root(TreeNode * head);

/*
 * @Name Value
 * @Args *head is the head of the tree
 *       index is the index of the node whose value is being needed
 * @Return the value of the input node
 */

TreeNode * GetNode(TreeNode * head);
int Value(TreeNode * head, int index);

/*
 * @Name Assign
 * @Args *head is the head of the tree
 *       index is the index of the node which is being modified
 *       value is the value
 * @Return Success or Failure
 */
void Assign(TreeNode * head, int index, int value);

/*
 * @Name Parent
 * @Args *head is the head of the tree
 *       index is the index of the node whose parent is being needed
 * @Return pointer to the parent of the input node
 */
TreeNode * Parent(TreeNode * head, int index);

/*
 * @Name LeftChild
 * @Args *head is the head of the tree
 *       index is the index of the node whose left child is being needed
 * @Return pointer to the left child of the input node
 */
TreeNode * LeftChild(TreeNode * head, int index);

/*
 * @Name RightChild
 * @Args *head is the head of the tree
 *       index is the index of the node whose right child is being needed
 * @Return pointer to the right child of the input node
 */
TreeNode * RightChild(TreeNode * head, int index);

/*
 * @Name LeftSibling
 * @Args *head is the head of the tree
 *       index is the index of the node whose left sibling is being needed
 * @Return pointer to the left sibling of the input node
 */
TreeNode * LeftSibling(TreeNode * head, int index);

/*
 * @Name RightSibling
 * @Args *head is the head of the tree
 *       index is the index of the node whose right sibling is being needed
 * @Return pointer to the right sibling of the input node
 */
TreeNode * RightSibling(TreeNode * head, int index);

TreeNode *getNode(TreeNode *head, int index);
/*
 * @Name InsertChild
 * @Args *head is the head of the tree
 *       index is the index of the chosen node
 *       LorR is the condition of which one of the children will be modified
 *       *subTree is another tree
 * @Return Success or Failure
 * @Tips subTree can be easily gotten by multi-trees
 */
int InsertChild(TreeNode * head, int index, int LorR, TreeNode * subTree, LinkQueue *Q);

/*
 * @Name DeleteChild
 * @Args *head is the head of the tree
 *       index is the index of the chosen node
 *       LorR is the condition of which one of the children will be modified
 * @Return Success or Failure
 */
int DeleteChild(TreeNode * head, int index, int LorR, LinkQueue *Q);

/*
 * @Name PreOrderTraverse
 * @Args *head is the head of the tree
 *       visit(value) is the function which is provided below
 * @Return Success or Failure
 */
int PreOrderTraverse(TreeNode * head, void (*visit)(int value));
int PreOrder(TreeNode * head, void (*visit)(int value));
/*
 * @Name InOrderTraverse
 * @Args *head is the head of the tree
 *       visit(value) is the function which is provided below
 * @Return Success or Failure
 */
int InOrderTraverse(TreeNode * head, void (*visit)(int value));
int InOrder(TreeNode * head, void (visit)(int value));

/*
 * @Name PostOrderTraverse
 * @Args *head is the head of the tree
 *       visit(value) is the function which is provided below
 * @Return Success or Failure
 */
int PostOrderTraverse(TreeNode * head, void (*visit)(int value));
int PostOrder(TreeNode * head, void (*visit)(int value));

/*
 * @Name LevelOrderTraverse
 * @Args *head is the head of the tree
 *       visit(value) is the function which is provided below
 * @Return Success or Failure
 */
int LevelOrderTraverse(TreeNode * head, void (*visit)(int value), LinkQueue *Q);

/*
 * @Name visit
 * @Args value is the variable being operated
 * @Return null
 * @Tips you can do what you wanna do here
 */
void visit(int value);
int max(int a, int b);

#endif //STRUCTUREEXPRUNITTEST_BINARY_TREE_H
