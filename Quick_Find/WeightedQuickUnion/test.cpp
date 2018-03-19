#include <iostream>
#include <fstream>

using namespace std;

void Change(FILE* file, int i){
    file = fopen("res1.txt", "w");
    fprintf(file, "%d", i);
}

int main(void){
    FILE *file;
    string buffer;

    fprintf(file, "%s", "value  ");
    for(int i=0; i<20; i++){
        Change(file, i);
    }

    return 0;
}
