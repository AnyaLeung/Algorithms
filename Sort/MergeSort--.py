def MergeSort(list, start, end):
    middle = (start + end) / 2
    MergeSort(list, start, middle)
    MergeSort(list, middle, end)

    while start == end:
        return list[start]
    
    

