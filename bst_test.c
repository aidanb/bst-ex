////////////////////////////////////////////////////////////////////////////////
// 
// test_tree.c
// 
// Program to test tree functions
// 
// Aidan Barrington
// 
////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

int main(int argc, char* argv[]) {
    
    
    printf("Test begins...now!\n");
    printf("Creating a new tree...\n");
    
    treeLink testTree;
    testTree = newTree(6);
    
    assert(countLeaves(testTree)==1);
    assert(countNodes(testTree) == 1);
    assert(maxDepth(testTree) == 1);
    printf("Pass!\n");
    
    printf("Adding more items...\n");
    addToTree(testTree,9);
    printTree(testTree);
    assert(countLeaves(testTree)==1);    
    assert(countNodes(testTree) == 2);
    assert(maxDepth(testTree) == 2);    
    printf("Passed.\n");
    
    printf("Adding more items...\n");
    addToTree(testTree,2);
    printTree(testTree);
    assert(countLeaves(testTree)==2);
    assert(countNodes(testTree) == 3);
    assert(maxDepth(testTree) == 2);    
    printf("Passed.\n");
    
    printf("Adding more items...\n");
    addToTree(testTree,5);
    printTree(testTree);
    assert(countLeaves(testTree)==2);
    assert(countNodes(testTree) == 4);       
    assert(maxDepth(testTree) == 3);        
    printf("Passed.\n");
    
    printf("Adding more items...\n");
    addToTree(testTree,500);
    printTree(testTree);
    assert(countLeaves(testTree)==2); 
    assert(countNodes(testTree) == 5);  
    assert(maxDepth(testTree) == 3);        
    printf("Passed.\n");
    
    printf("Checking checkTree function...\n");
    printf("Looking for all numbers added so far...\n");
    assert(checkTree(testTree,6));
    assert(checkTree(testTree,9));
    assert(checkTree(testTree,2));
    assert(checkTree(testTree,5));
    assert(checkTree(testTree,500));
    printf("Test passed!\n");
    
    printf("Checking depth function...\n");
    printf("Depth: %d\n", maxDepth(testTree));
    
    printf("All tests passed, you are AWESOME!\n");
        
    
return EXIT_SUCCESS;    
}
