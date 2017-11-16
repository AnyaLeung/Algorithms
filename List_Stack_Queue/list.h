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

struct Node{
    Elem_type Element;
    Position Next;
};

/* Return true if L is empty */
int Is_empty(List L){
    return L->next == NULL;
}

/* Return true if L is last node */
int Is_last(Position P, List L){
    return P->next == NULL;
}

List Init(){
   List header = malloc(sizeof(Node));
   return header;
}

Position Find(Elem_type X, List L){ //find position of ele with value p
    Ptr_to_node q;
    q = L->Next;

    //***
    while(q!=NULL && q->Element!=X){ 
        q = q->Next;
    }
    return q; 
    //***
    //遍历直到找到想要的值/到尾巴也没得
    
} //provided q is NULL, it stops while NUll, also returns NULL

void Delete(Elem_type X, List L){
    if(L->Next==NULL) return;

    Prt_to_no p;
    p = L->Next;

    while(p!=NULL && p->Next!=)
} //Delete first occurrence of X from a list

void Insert(Elem_type X, List L, Position P){
   //insert Node with value X, after P
   Position q, tmp;

   q = L->next;
   while(q->Elem!=P && q){
       q = q->Next;
   }

   tmp->Elem = X;
   tmp->Next = q->Next;
   q->Next = tmp;
} 
