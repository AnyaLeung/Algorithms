#include <stdio.h>
#include <stdlib.h>
#define Elem_type int

struct Node;
typedef struct Node *Ptr_to_node; //PtrToNode --> pointer to node
typedef Ptr_to_node List; 
typedef Ptr_to_node Position;

/* List with header L*/

/* function prototype */
List Make_empty(List L);
int Is_empty(List L);
int Is_last(Position P, List L);
Position Find(Elem_type X, List L);
void Insert(Elem_type X, List L, Position P);
void Delete_list(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
Elem_type Retrieve(Position P); //取回..?
/* function prototype */
// L is head pointer

struct Node{
    Elem_type Element;
    Position Next;
};

/* Return true if L is empty */
int Is_empty(List L){
    return L->Next == NULL;
}

/* Return true if L is last node */
int Is_last(Position P, List L){
    return P->Next == NULL;
}

List *Init(){
   List *header = malloc(sizeof(Node));
   header->next = NULL;
   return header;
}

Position Find(Elem_type P, List L){ //find position of ele with value p
    Ptr_to_node q;
    q = L->Next;

    if(q==NULL) return NULL;

    while(q->Next!=P && q){
        q = q->Next;
        //if(q->Element==P) return q;
        //else q = q->Next;
    }
    return q; 
    //provided q is NULL, it stops while NUll, also returns NULL
}

void Insert(Elem_type X, List L, Position P){
   //insert Node with value X, after P
   Position q, tmp;

   q = L->Next;
   while(q->Elem!=P && q){
       q = q->Next;
   }

   tmp->Elem = X;
   tmp->Next = q->Next;
   q->Next = tmp;
} 

int main(void){
    List *L = Init();
    cout << Is_empty();
    return 0;
}
