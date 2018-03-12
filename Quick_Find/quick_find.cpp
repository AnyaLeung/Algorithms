#include <iostream>
//#define N 20

using namespace std;

int *id;

//ok
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
    int v2_root = Find(value1);
    int v1_root = Find(value2);

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
}

int main(void){
    UF(20);

    return 0;
}
