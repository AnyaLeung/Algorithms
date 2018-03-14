/*
 * O(n)
 */
#include <iostream>
#include <fstream>

using namespace std;

/* global variable */
int *id;
int N = 20;

/* fuction prototype */
void UF(void);
int Find(int value1);
bool Connected(int value1, int value2);
void Union(int value1, int value2);
void PrintArr(void);
/* fuction prototype */

/* fuction definition */
void UF(void){
    id = new int[N];
    for(int i=0; i<N; i++){
        id[i] = i;
    }
} //Init id[N]

int Find(int value1){
    return id[value1];
} //return value1's root

bool Connected(int value1, int value2){
    return id[value1] == id[value2];
} //same root --> true, diff root --> false

void Union(int value1, int value2){
    int v1_root = Find(value1);
    int v2_root = Find(value2);

    if(v1_root==v2_root){
        cout << "is connected" << endl;
        return;
    }
    else{
        for(int i=0; i<N; i++){
            if(id[i]==v1_root)
                id[i] = v2_root;
        }
    }
    PrintArr();
}

void PrintArr(void){
    cout << "value  ";
    for(int i=0; i<N; i++){
        cout << i << " " ;
    }
    cout << endl;

    cout << "father ";
    for(int i=0; i<N; i++){
        cout << id[i] << " ";
    }
    cout << endl << endl;
}

//prototype
/* fuction definition */

int main(void){
    UF();
    Union(1, 2);
    Union(0, 1);
    return 0;
}
