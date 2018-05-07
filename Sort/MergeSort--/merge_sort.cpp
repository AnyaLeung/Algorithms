//descanding order

bool Less(int a, int b){
   return a<b;
}

 void Merge(int lo, int hi, int arr[], int res[]){
     int mid = (lo + hi) / 2;
     int i = lo, j = mid + 1;

     for(int k=lo; k<=hi; k++){
         if(i>mid) 
             res[k] = arr[j++];
         if(j>hi)  
             res[k] = arr[i++];
         //如果一個都存進去了 另一個還沒整完

         if(Less(arr[i], arr[j]))   
             res[k] = arr[j++];
         else 
             res[k] = arr[i++];
     }
}

void Sort(int lo, int hi, int arr[], int res[]){
    if(hi<=lo) return;
    int mid = lo + (hi - lo) / 2;
    Sort(lo, mid, arr, res);
    Sort(mid, hi, arr, res);
    Merge(lo, hi, arr, res);
}
