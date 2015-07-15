#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

struct treeNode {
  Item item;
  treeLink left, right;
};

//Static function that makes printing the tree easier. :) Enjoy
static void printTreeA(treeLink tree, int height);


//Creates a new tree with root a
//Already written for you, see tree.c
treeLink newTree(Item a) {
  treeLink new = malloc (sizeof(struct treeNode));
  new ->item = a;
  new->left = NULL;
  new->right = NULL;
  return new;
}

//adds a node to the tree in no particularly defined way
//Already written for you, see tree.c
treeLink addToTree(treeLink t, Item a) {
  if (t == NULL) {
    t = newTree(a);
  } else {
    if (t->item < a) {
      t->right = addToTree(t->right, a);
    } else {
      t->left = addToTree(t->left, a);
    }
  }
  return t;
}

//frees memory and returns NULL if successful
//Already written for you, see tree.c
treeLink deleteTree(treeLink t) {
  if (t != NULL) {
    t->right = deleteTree(t->right);
    t->left = deleteTree(t->left);
    free(t);
  }
  return NULL;
}

static void printTreeA(treeLink tree, int height) {
  if (tree != NULL) {
    printTreeA(tree->left, height +1);
    int i;
    for (i = 0; i < height; i++){
      printf("   ");
    }
    printf("%d\n", tree->item);
    printTreeA(tree->right, height + 1);
  }
}

void printTree(treeLink tree) {
  printTreeA(tree, 0);
}



// function to count the number of leaves 
// in a tree structure
// Note that a leaf is any node on the tree with ZERO children
// this function should return 0 if tree is NULL
int countLeaves(treeLink tree) {

    if (tree == NULL) {
        return 0;
    }
    
    if (tree->left == NULL && tree->right == NULL) {
        return 1;
    } else {
        return (countLeaves(tree->left) + countLeaves(tree->right));
    }
}


//checks the tree for a given item
bool checkTree(treeLink t, Item a){
 
    bool inTree = FALSE;
    
    while (!inTree) {
        if (t != NULL) {
            if (t->item == a) {
                inTree = TRUE;
            } else {
                if (a < t->item) {
                    inTree = checkTree(t->left, a);
                } else {
                    inTree = checkTree(t->right,a);
                }
            }
        }
    }
return inTree;
}

//counts all nodes in tree
int countNodes(treeLink t){
 
    int size = 0;
    
    if (t != NULL) {
        size = 1 + countNodes(t->left) +
                   countNodes(t->right);
    }
return size;
}



// determines the maximum depth of the tree structure
int maxDepth(treeLink t){
    
    int depth = 0;
    int leftDepth = 0;
    int rightDepth = 0;
    //every time we descend we add one to the counter
    
    if (t != NULL) {
        
        leftDepth = maxDepth(t->left);
        rightDepth = maxDepth(t->right);
    
        if (leftDepth > rightDepth){
            depth = leftDepth + 1;
        } else {
            depth = rightDepth + 1;
        
        }
    }
    
    
return depth;
}








