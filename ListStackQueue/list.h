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
Position Find_previous(Elem_type X, List L);
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
    Position p;

    p = L->Next;
    /* *** */
    while(p!=NULL && p->Element!=X)
        p = p->Next;
    
    return p;
    /* *** */
    //遍历直到找到想要的值/到尾巴也没得
} //provided q is NULL, it stops while NUll, also returns NULL

Position Find_previous(Elem_type X, List L){
    Position P;
    P = L->Next;

    while(P!=NULL && (P->Next)->Element=X){
        P = P->Next;
    }
    return p;
}

void Delete(Elem_type X, List L){
    if(L->Next==NULL) return; //if list is empty

    Position p;
    Node tmp;

    p = Find_previous(X, L); //刪除要記住前繼node!!
    if(!Is_last(p, L)){
        tmp = p->Next; //wanna delete tmp
        p->Next = tmp->Next; 
        free(tmp);
    }
} //Delete first occurrence of X from a list

void Insert(Elem_type X, List L, Position P){
   //insert Node with value X, after P
   Position tmp;
   Node ins;
   ins.Element = X;

   tmp = P->Next;
   P->Next = ins;
   ins->Next = tmp;
} 
//linked list is linked by pointer
//so if you give a pointer point to the element
//it means you can reach that node
