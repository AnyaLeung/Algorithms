// why inside comments are not right?
//
struct node* insert(struct node* node, int data)
{
    //if is root node or leaf's child
    if(node==NULL) return newNode(data);
    
    struct node* pre = node;
    if(data<pre->data){
        /*
        pre = pre->left;
        pre = insert(pre, data);
        */
        pre->left = insert(pre->left, data);
    }
    else if(data>pre->data){
        /*
        pre = pre->right;
        pre = insert(pre, data);
        */
        pre->right = insert(pre->right, data);
    }
    else if(data==pre->data){
        return node;
    }
    return node;
}
