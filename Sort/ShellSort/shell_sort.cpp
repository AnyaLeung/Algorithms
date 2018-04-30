//unfinished
/*
#include <iostream>

using namespace std;
*/

int* ShellSort(int arr[], int total){
    int h = 1;
    while(h<N/3){
        h = 3 * n + 1; //biggest (3*n+1) window
    }

    while(h>=1){
        for(int i=h; i<total; i++){
            for(int j=i; j>0; j--){
                if(arr[j]<arr[j-1])
                    swap(arr[j], arr[j-1]);
                else break;
            }
        }//insertion sort
        h = h / 3;
    }
}

/*
int main(void){

    return 0;
}
*/
