#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    FILE *file;
    string buffer;

    file = fopen("res1.txt", "w");


    fprintf(file, "%s", "value  ");
    for(int i=0; i<20; i++){
        fprintf(file, "%d", i);
        fprintf(file, "%c", ' ');
        fprintf(file, "%c", '\n');
        fprintf(file, "%c", '\n');
    }



    fprintf(file, "%s", "Hahhahaha");
    return 0;
}
