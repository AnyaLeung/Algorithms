#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void){
    int tmp1 = 0, tmp2 = 0;
    string name;
    int choice = 0;
    int N= 0; //id[] length

    cout << "Enter [1] to load case1_input," << endl;
    cout << "Enter [2] to load case2_input: " << endl;
    cin >> choice;

    if(choice==1)
        name = "case1_input.txt";
    if(choice==2)
        name = "case2_input.txt";

    ifstream infile(name);
    infile >> tmp1;
    infile >> tmp2;

    N = (tmp1>tmp2)? tmp1 : tmp2;

    cout << N;

    return 0;
}
