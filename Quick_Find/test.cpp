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
void PrintArr(void);
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
    PrintArr();
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
    PrintArr();
} 

void PrintArr(void){
    cout << "value  "; for(int i=0; i<20; ++i){
        cout << i << " " ;
    }
    cout << endl;

    cout << "father ";
    for(int i=0; i<20; ++i){
        cout << id[i] << " ";
    }
    cout << endl;

    cout << "weight ";

    for(int i=0; i<20; ++i){
        if(Root(i)!=id[i]){
            cout << 0 << " ";
            continue;
        } //if not root then weight 0
        cout << Size(i) << " ";
    }
    cout << endl << endl;
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



/*
//prototype
string GetFileName(){
int choice = 0;

cout << "Enter [1] to load case1_input," << endl;
cout << "Enter [2] to load case2_input: " << endl;
cin >> choice;

if(choice==1)
return "case1_input.txt";
if(choice==2){
return  "case2_input.txt";
}
}
*/


/*
   void InputFileProcess(void){
   int N = 0; // id[] length
   int tmp1 = 0, tmp2 = 0;
   string name;
   name = GetFileName();
   ifstream = infile(name);

   infile >> tmp1;
   infile >> tmp2;

   N = (tmp1>tmp2)? tmp1 : tmp2;
//按理來說到這裡已經讀了前兩行 知道了id[]的length

while(!infile.eof()){
infile >> tmp1 >> tmp2;
cout << tmp1 << tmp2;
}
} //我他媽不會寫file啊真是要跪了
//後幾行要把兩個參數的讀進去 然後union
//還需要把結果存到file裡 怕了怕了 我去看computer orginization了。。
//
*/

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

