struct Node;
struct Node *Ptr_to_node; //PtrToNode --> pointer to node
struct Ptr_to_node list; 
struct Ptr_to_node Position;

/* List with header */

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

Position Find(Elem_type P, List L){
    
}
