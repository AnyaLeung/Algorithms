//問ta weight怎麼算的emm
#include <iostream>
#include <fstream>

using namespace std;

/* global variable */
int *id;
int N = 0;
int *size;
string output_file_name;

/* fuction prototype */
void UF(int N);
bool Connected(int value1, int value2);
int Root(int value1);
void Union(int value1, int value2);
void PrintArrToFile(bool flag);
void ReadFileAndUnion(string filename);
void GetN(string filename);
/* fuction prototype */

/* fuction definition */
void UF(int N){
    id = new int[N];
    size = new int[N];
    for(int i=0; i<N; ++i){
        id[i] = i;
        size[i] = 1;
    }
    //PrintArrToFile(false);
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
        PrintArrToFile(true);
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
        PrintArrToFile(false);
    }
}


void PrintArrToFile(bool flag){
    FILE* file;
    file = fopen("res1", "a");
    if(flag){
        fprintf(file, "%s", "connect.\n");
        return ;
    }
    else{
        char buffer[1000];

        fprintf(file, "%s", "value  ");
        for(int i=0; i<N; ++i){
            fprintf(file, "%d", i);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');

        fprintf(file, "%s", "father ");
        for(int i=0; i<N; ++i){
            fprintf(file, "%d", id[i]);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');


        fprintf(file, "%s", "weight ");
        for(int i=0; i<N; ++i){
            fprintf(file, "%d", size[i]);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');
        fprintf(file, "%c", '\n');
    }
}

void ReadFileAndUnion(string filename){ 
    fstream file;;
    char buffer[100];
    file.open(filename);

    file.getline(buffer, sizeof(buffer));
    char *p = buffer;
    int opr1 = 0, opr2 = 0;

    file.getline(buffer, sizeof(buffer)); //skip line 1 and line2

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
                    opr1 += int(*q) - '0'; q++;
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
                Union(opr1, opr2);
            }
        }while(!file.eof());
    }
}

void GetN(string filename){
    fstream file;;
    char buffer[10];

    file.open(filename);
    file.getline(buffer, sizeof(buffer));

    char *p = buffer;
    while(*p>='0' && *p<='9'){
        N *= 10;
        N += int(*p) - '0';
        p++;
    }
}

int main(void){
    GetN("c.txt");
    UF(N);
    output_file_name = "res1.txt";

    ReadFileAndUnion("c.txt"); 
    return 0;
}
