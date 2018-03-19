#include <iostream>
#include <fstream>

using namespace std;

/* global variable */
int *id;
int N = 40;
int *size;

/* fuction prototype */
void UF(int N);
bool Connected(int value1, int value2);
int Root(int value1);
void Union(int value1, int value2);
void PrintArr(bool flag();
int Size(int root);
void InputFileProcess(void);
/* fuction prototype */

/* fuction definition */
void UF(int N){
    id = new int[N];
    size = new int[N];
    for(int i=0; i<N; ++i){
        id[i] = i;
        size[i] = 0;
    }
    PrintArr(flag);
} //Init id[N]

bool Connected(int value1, int value2){
    return id[value1] == id[value2];
} //same root --> true, diff root --> false

int Root(int value1){
    while(id[value1]!=value1){
        value1 = id[value1];
    }
    return value1;
}

void Union(int value1, int value2){
    int v1_root = Root(value1);
    int v2_root = Root(value2);

    if(v1_root==v2_root){
        cout << "Connected" << endl;
        PrintArr(true);
        return;
    }
    else{
       if(size[v1_root]>size[v2_root]){

       }
        int res = (Size(v1_root) > Size(v2_root))? 1 : 0;
        //tree root1 is smaller return 1, else return 0

        if(res==1){
            id[v2_root] = v1_root;

        }
        if(res==0){
            id[v1_root] = v2_root; } }
    PrintArr(false);
} 

void PrintArr(bool flag){
    FILE* file;
    file = open("res1", "a");
    
    if(flag){
        fprintf(file, "%s" "Connect. \n");
        return ;
    }
    else{
        char buffer[1000];

        fprintf(file, "%s", "value  ");
        for(int i=0; i<20; ++i){
            fprintf(file, "%d", i);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');

        fprintf(file, "%s", "father ");
        for(int i=0; i<20; ++i){
            fprintf(file, "%d", id[i]);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');

        fprintf(file, "%s", "weight ");
        for(int i=0; i<20; ++i){
            if(Root(i)!=id[i]){
                cout << 0 << " ";
                continue;
            } //if not root then weight 0
            cout << Size(i) << " ";
        }
        cout << endl << endl;
    }
}

int Size(int root){
    int count = 0;

    for(int i=0; i<N; ++i){
        if(Root(id[i])==root && i!=id[i] ){
            count ++; 
        }
    }
    return count; //except itself
} // size of node's tree



/* fuction definition */

int main(void){
    UF(40);
    Union(1, 7);
    Union(14, 0);
    Union(9, 4);
    Union(18, 18);
    Union(2, 4);
    Union(5, 5);
    Union(1, 7);
    Union(1, 11);
    Union(15, 2);
    Union(7, 16);
    Union(11, 4);
    Union(2, 13);
    Union(12, 2);
    Union(1, 16);
    Union(18, 15);
    Union(7,6);
    Union(11,18);
    Union(9,12);
    Union(7,19);
    Union(15,14);
    Union(3,11);
    Union(2,13);
    Union(13,4);
    Union(1,11);
    Union(13,8);
    Union(7,4);
    Union(2,17);
    Union(17,19);
    Union(3,1);
    Union(9,18);
    Union(16,15);
    Union(10,2);
    Union(8,6);
    Union(0,2);
    Union(4,8);
    Union(6,5);
    Union(10,9);
    Union(10,10);
    Union(6,1);
    Union(13,8);
    //read and process file and output into txt f*ck
    return 0;
}
