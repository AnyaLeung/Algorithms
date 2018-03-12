//要死 寫的是quick find 不是quick union。。
#include <iostream>
//#include <string>
#include <fstream>

using namespace std;

/* global variable */
int *id;

/* fuction prototype */
void UF(int N);
int Find(int value1);
bool Connected(int value1, int value2);
void Union(int value1, int value2);
void PrintArr(void);
/* fuction prototype */

/* fuction definition */
void UF(int N){
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
        cout << "is connected";
        return;
    }
    else{
        for(int i=0; i<20; i++){
            if(id[i]==v1_root)
                id[i] = v2_root;
        }
    }
    PrintArr();
}

void PrintArr(void){
    cout << "value  ";
    for(int i=0; i<20; i++){
        cout << i << " " ;
    }
    cout << endl;

    cout << "father ";
    for(int i=0; i<20; i++){
        cout << id[i] << " ";
    }
    cout << endl << endl;
}

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

/* fuction definition */

int main(void){
    UF(N);
    return 0;
}
