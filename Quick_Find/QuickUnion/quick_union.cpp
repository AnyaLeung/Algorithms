#include <iostream>
#include <fstream>

using namespace std;

/* global variable */
int *id;
int N = 0;
string output_file_name;

/* fuction prototype */
void UF(int N);
void GetN(string filename);
bool Connected(int value1, int value2);
int Root(int value1);
void Union(int value1, int value2);
void PrintArr(bool flag);
void ReadFileAndUnion(string filename);
/* fuction prototype */

/* fuction definition */
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

void UF(int N){
    id = new int[N];
    for(int i=0; i<N; ++i){
        id[i] = i;
    }
    PrintArr(false);
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
        PrintArr(true);
        return;
    }
    else{
        id[v1_root] = id[v2_root];
    }
    PrintArr(false);
}

void PrintArr(bool flag){
    FILE* file;
    file = fopen(output_file_name.c_str(), "a");
    if(flag){
        fprintf(file, "%s", "connect.\n");
        return ;
    }
    else{
        char buffer[1000];

        fprintf(file, "%s", "value  ");
        for(int i=0; i<N; ++i){ fprintf(file, "%d", i);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');

        fprintf(file, "%s", "father ");
        for(int i=0; i<N; ++i){
            fprintf(file, "%d", id[i]);
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
/* fuction definition */

int main(void){
    GetN("case1_input.txt");
    cout << "Reading case1_input now..." << endl;
    output_file_name = "case1_output.txt";
    UF(N);
    ReadFileAndUnion("case1_input.txt");
    cout << "Print as case1_output.txt" << endl;
    cout << endl;

    N = 0;
    output_file_name = "";

    GetN("case2_input.txt");
    cout << "Reading case2_input now..." << endl;
    output_file_name = "case2_output.txt";
    UF(N);
    ReadFileAndUnion("case2_input.txt");
    cout << "Print as case2_output.txt" << endl;
    cout << endl;

    N = 0;
    output_file_name = "";

    char op;

    while(op!='x'){
        cout << "Enter [e] for more case, [x] to exit: ";
        cin >> op;
        if(op=='e'){
            string input;
            string output;
            cout << "Input file name: ";
            cin >> input;
            cout << "Input output file name: ";
            cin >> output;
            N = 0;
            GetN(input.c_str());
            UF(N);
            ReadFileAndUnion(output);
            cout << "Complete.";
        }
    }
    return 0;
}

