#include <iostream>

using namespace std;

class Node{
    }

public class BST{
    private Node root;
    private class Node{
        private Key key; //id
        private Value val; //value
        private Node left, right;

        public Node(Key key, Value val){
            this.key = key;
            this.val = val;
        }
    }

    public bool put(Node root, Key key, Value val){
        Node x = root;

        if(x->value==value){
            return false;
        {
            if(x.key>key){
                x = x->left;
                if(x==NULL) x = new BSTNode(value);
                else        put(x, key, val);

                }
            else if(x.key<key){
                x = x->right;
                if(x==NULL) x = new BSTNode(value);
                else        put(x, key, val);
            }
        }
    }

    public Value get(Key key){ //key is the dest key
        Node x = root;
        while(x!=NULL){
            if(x.key > key){
                x = x.left;
            }
            else if(x.key < key){
                x = x.right;
            }
            else if(x.key==key){
                return x.val;
            }
        }
        return NULL;
    }

    public void delete(Key key){
        
    }

    public Iterable<Key> iterator(){

    }
}
