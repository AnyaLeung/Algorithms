#include <iostream<

using namespace std;

struct NODE* GetKey(struct NODE* head, int tar_val){
    struct Node current = head;
    struct Node *res;

    while(current!=NULL){
        if(current.val<tar_val)
            current = current.right;
        if(current.val>tar_val)
            current = current.left;
        if(current.val==tar_val){
            res = *current;
            return res;
        }
        return NULL;
    }
} //search val with BST's same method
