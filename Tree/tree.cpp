#include <iostream>
#include "tree.h"

using namespace std;

SearchTree MakeEmpty(SearchTree T){
    while(T->Left || T->Right){
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
    }
    free(T);
}

Position Find(ElementType X, SearchTree T){
    if(!T) return NULL;
    while(T->Left || T->Right){
        if(T->Element==X) return *T;
        else{
            Find(X, T->Left);
            Find(X, T->Right);
        }
    }
    return NULL;
}

Position FindMin(SearchTree T){
    Position min_po;
    if(!T) return NULL;
    while(T->Left || T->Right){
        if(T->Element < min_po->Element){
            int tmp = min_po->Element;
            min_po->Element = T->Element;
            T->Element = tmp;
        } //smaller then exchange value
        else{
            FindMin(T->Left);
            FindMin(T->Right);
        }

    }
    return min_po;
}

Position FindMax(SearchTree T){
    Position max_po;
    if(!T) return NULL;
    while(T->Left || T->Right){
        if(T->Element < max_po->Element){
            int tmp = max_po->Element;
            max_po->Element = T->Element;
            T->Element = tmp;
        } //smaller then exchange value
        else{
            FindMax(T->Left);
            FindMax(T->Right);
        }

    }
    return max_po;
}

SearchTree Insert(ElemntType X, SearchTree T){
    /*
     * if leave-->delete directly
     * if one child-->use this child to substitude
     * if two child-->use min of right child tree to substitude
     *                (or max of left child tree to substitude
     */
    if(!T) return NULL;
}

int main(void){

    return 0;
}
