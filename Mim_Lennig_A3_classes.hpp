//
//  Mim_Lennig_A3_classes.hpp
//  Mim_Lennig_A3
//
//  Created by Miriam Lennig on 2016-10-09.
//  Copyright © 2016 Mim Lennig. All rights reserved.
//

#ifndef Mim_Lennig_A3_classes_hpp
#define Mim_Lennig_A3_classes_hpp

#include <iostream>
#include <string>
using namespace std;

class MergeSort {
    void merge(double arrayA [], int sizeA, double arrayB[], int sizeB);    // Merge sort function
    double dataToSort[100005];
    int sizeDataToSort;
    void recMergeSort(double [], int, int);     // Recursive merge sort function
    void itMergeSort(double workSpace[]);   // Iterative merge sort function
    
public:
    void iterativeSort();
    MergeSort(string);  // Constructor creates a file 
    void print();
    void writeResults2File(string);
    void recursiveSort();
    bool isSorted();    // Check to see if data has been sorted
};

#endif /* Mim_Lennig_A3_classes_hpp */
