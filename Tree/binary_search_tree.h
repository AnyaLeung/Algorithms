#include <iostream>
#define DataType int

using namespace std;

/* function prototype */
void MakeEmpty(Tree T);
Position Find(DataType X, Tree T);
Position FindMin(Tree T);
//Position FindMin(Tree T);
Tree Insert(DataType X, Tree T);
Tree Delete(DataType X, Tree T):
DataType Retrive(Position P);

/* function prototype */

/* declartion of tree */
struct TreeNode; 
typedef struct TreeNode* Position;
typedef Position Tree;

struct TreeNode{
    DataType Data;
    Position Left;
    Position Right;
};
/* declartion of tree */

void EmptyTree(Tree T){
    if(T){
        EmptyTree(T->Left);
        EmptyTree(T->Right);
    }
    free(T);
}

Position Find(DataType X, Tree T){
    if(!T) return null;

    Position p;
    p = T;
    while(p->Data!=X){
        Find(p->Left);
        Find(p->Right);
    }
}
