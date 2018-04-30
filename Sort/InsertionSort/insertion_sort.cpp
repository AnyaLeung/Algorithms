//unfinished
#include <iostream>

using namespace std;

struct LIST* InsertionSort(struct LIST* head);

int main(void){

    return 0;
}

int* InsertSort(int arr[], int no){
    for(int i=1; i<total; i++){
        for(int j=i; i>0; j--){
            if(arr[j]<arr[j-1])
                swap(arr[j], arr[j-1]);
            else break;
        }
}

//小的往前放左邊
//和前面的比較，如果比前面的小就和前面的前面比較，直到不比它小
