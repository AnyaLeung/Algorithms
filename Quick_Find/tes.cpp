#include <string>
#include <sstream>

using namespace std;

int main(void){
    string line = "tet.txt";
    double d;

    getline(line)
    while (getline(line)){
        stringstream ss(line);
        if(ss>>d){
            if (ss.eof()){   // Success
                break;
            }
        }
        cout << "Error!" << endl;
    }
    cout << "Finally: " << d << endl;
}
