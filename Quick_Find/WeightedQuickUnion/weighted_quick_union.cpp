//明天完善：
//改一下N和輸出的函數的N
//寫一下輸出文件
//寫一下N get的func
//問ta weight怎麼算的emm
//終於debug完了累死我了。。。。

#include <iostream>
#include <fstream>

using namespace std;

/* global variable */
int *id;
int N = 100;
int *size;

/* fuction prototype */
void UF(int N);
bool Connected(int value1, int value2);
int Root(int value1);
void Union(int value1, int value2);
void PrintArr(void);
void ReadFileAndUnion(string filename);
/* fuction prototype */

/* fuction definition */
void UF(int N){
    id = new int[N];
    size = new int[N];
    for(int i=0; i<N; ++i){
        id[i] = i;
        size[i] = 1;
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
            id[v2_root] = v1_root;
            size[v1_root] += size[v2_root];
        }
        else{
            id[v1_root] = v2_root; 
            size[v2_root] += size[v1_root];
        } 
    }
    PrintArr();
} 

void PrintArr(void){
    cout << "value  "; 
    for(int i=0; i<20; ++i){
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
        /*
        if(Root(i)!=id[i]){
            cout << 0 << " ";
            continue;
        } //if not root then weight 0
        */
        cout << size[i] << " ";
    }
    cout << endl << endl;
}

void ReadFileAndUnion(string filename){ 
    fstream file;;
    char buffer[100];
    file.open(filename);

    file.getline(buffer, sizeof(buffer));
    char *p = buffer;
    int opr1 = 0, opr2 = 0;

    while(*p){
        N *= 10;
        N += int(*p) - '0';
        p++;
    } //get N
    file.getline(buffer, sizeof(buffer)); //skip union count

    if(!file){
        cout << "cannot open file" << endl;
    }
    else{
        do{
            file.getline(buffer, sizeof(buffer));
            char *q = buffer;
            bool enter_flag = false;
            bool op2_flag = false;
            opr1 = 0;
            opr2 = 0;
            while(*q){
                enter_flag = true;
                if(!op2_flag){
                    opr1 *= 10;
                    opr1 += int(*q) - '0';
                    q++;
                }
                while(*q==' '){
                    q++;
                    op2_flag = true;
                }

                if(op2_flag){
                    opr2 *= 10;
                    opr2 += int(*q) - '0';
                    q++;
                }
            }

            if(enter_flag){
                //cout << opr1 << "  " << opr2 << endl;
                Union(opr1, opr2);
            }
        }while(!file.eof());
    }
}

int main(void){
    UF(N);
    ReadFileAndUnion("c.txt"); 
    Union(41, 17);

    return 0;
}
