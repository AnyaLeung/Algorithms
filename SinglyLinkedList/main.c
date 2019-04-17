#include "sll_node.h"
#define FALSE 0
#define TRUE  1

int Insert(Node **linkp, int new_value){
    /*
     * find the place of insertion
     */
    register Node *current;
    register Node *new;

    while((current=*linkp)!=NULL&& (current->value)>=new_value){
        linkp = &(current -> link);
        //printf("%ld \n", linkp);
    }


    /*
     * create new node,
     * if failed, return false
     */ 
    new = (Node *)malloc(sizeof(Node));
    if(new==NULL){
        return FALSE;
    }
    new->value = new_value;

    /*
     * insert into linked list, return truek:w
     */
    new->link = current;
    *linkp = new;
    return TRUE;
}

void Iterate(const Node *linkp){
    int count = 0;
    Node *p;
    p = linkp;
    do{
        printf("%d %d\n", count++, p->value);
    }while((p=p->link)!=NULL);
    
    printf("\n");
}

/*
 * return a pointer pointing to aiming
 * if not found, return NULL
 */
Node* Find(const Node *linkp, int find_value){
    Node *current;
    while((current=linkp)!=NULL && current->value!=find_value){
        linkp = linkp->link;
    }
    return current; 
}

/*
 *  delete value with del_value
 */
void Delete(Node **linkp, int del_value){
}

int main(void){
    /*
     * define a struct pointer,
     * it NEEDS 2b init 2 NULL!
     */
    Node* root = NULL;

    /*
     * insert tests
     */
    int result = 0;
    result = Insert(&root, 9);
    result = Insert(&root, 8);
    result = Insert(&root, 2);
    result = Insert(&root, 3);
    result = Insert(&root, 4);
    Iterate(root);

    /*
     * find tests
     */
    Node* res = NULL;
    res = Find(root, 3);
    Iterate(res);
    res = Find(root, 10);
    return 0;
}
