#define TRUE  1
#define FALSE 0

typedef int Item;
typedef int bool;
typedef struct treeNode *treeLink;

int countLeaves(treeLink tree);

//Creates a new tree with root a
/*Already written for you, see tree.c*/
treeLink newTree(Item a);

//adds a node to the tree in no particularly defined way
/*Already written for you, see tree.c
* Note that this is because we havent said that this is a tree, not necessarily
* a BST or any other trees. (It could be a ternary tree even)
* The count function you implement is in a BST implementation of a tree (as below)
* But the question becomes how can you test a .h file with bad descriptor of what 
* its functions should do?
* Think on it.
*/
treeLink addToTree(treeLink t, Item a);

//frees memory and returns NULL if successful
/*Already written for you, see tree.c*/
treeLink deleteTree(treeLink t);

/*Already written for you, see tree.c*/
void printTree(treeLink tree);


// checks the tree for an item
bool checkTree(treeLink t, Item a);

//counts all the nodes in the tree
int countNodes(treeLink t);

// determines the maximum depth of the tree structure
int maxDepth(treeLink t);
