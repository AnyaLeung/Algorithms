#include <iostream>
#include "binary_search_tree.h"

using namespace std;

int main(void){
    struct TreeNode no, no1, no2;
    no.Data = 5;
    *(no->Left) = no1;
    *(no->Right) = no2;
    no->Right = no2;
    no1.Data = 3;
    no1->Left = null;
    no1->Right = null;
    no2.Data = 7;
    no2->Left = null;
    no2->Right = null;
    return 0;
}
