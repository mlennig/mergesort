//
//  Mim_Lennig_A3_classes.cpp
//  Mim_Lennig_A3
//
//  Created by Miriam Lennig on 2016-10-09.
//  Copyright © 2016 Mim Lennig. All rights reserved.
//

#include "Mim_Lennig_A3_classes.hpp"
#include <iostream>
#include <array>
#include <fstream>
#include <string>
using namespace std;

void MergeSort::merge(double arrayA [], int sizeA, double arrayB [], int sizeB) {
    // Merge sort arrayA & arrayB
    int aDex = 0;                                           // Index into arrayA
    int bDex = 0;                                           // Index into arrayB
    int sortDex = 0;                                       // Index into sorted array
    double sortedArray[sizeA + sizeB];            // Sorted array will be the merged size of arrayA & arrayB
    
    while ((aDex < sizeA) && (bDex < sizeB)){
        // Neither array is empty
        if (arrayA[aDex] < arrayB[bDex])
            sortedArray[sortDex++] = arrayA[aDex++];
        else
            sortedArray[sortDex++] = arrayB[bDex++];
    }
    
    while (bDex < sizeB)
        // arrayA has emptied and arrayB has not
        sortedArray[sortDex++] = arrayB[bDex++];
        
    while (aDex < sizeA)
        // arrayB has emptied and arrayA has not
        sortedArray[sortDex++] = arrayA[aDex++];
    
    for(int i = 0; i < sizeA + sizeB; i++)
        arrayA[i] = sortedArray[i];
    
};

void MergeSort::print(){
    for(int i = 0; i < sizeDataToSort; i++)
        cout << dataToSort[i] << endl;
};

MergeSort::MergeSort(string fileName){
    ifstream iFile;
    string line;
    unsigned index = 0;
    
    iFile.open("sortinput.txt");
    
    while(getline(iFile, line)){
        if (index >= 100000)
            break;
        dataToSort[index++] = stod(line);   // Convert string to double, add it to dataToSort array. Increase index.
    }
    iFile.close();
    
    sizeDataToSort = index;
};

void MergeSort::writeResults2File(string s){
    ofstream oFile;
    oFile.open(s);
    
    for(int i = 0; i < sizeDataToSort; i++)
        oFile << dataToSort[i] << endl;
    
    oFile.close();
}

void MergeSort::recMergeSort(double workSpace [], int LB, int UB) {
        if (LB == UB)   // Return if indices are pointing to the same element.
            return;
        else {
            int mid = (LB + UB) / 2;    // Find midpoint value
            recMergeSort(workSpace, LB, mid);   // Split up LHS
            recMergeSort(workSpace, mid+1, UB); // Split up RHS
            merge(&workSpace[LB], mid - LB + 1, &workSpace[mid + 1], UB - mid);     // Merge LHS & RHS arrays
        }
}

void MergeSort::itMergeSort(double workSpace[]){
    int N = sizeDataToSort;
    for (int mergeSz = 1; mergeSz < N; mergeSz += mergeSz){     // mergeSz is the size of the LHS & RHS arrays to be merge sorted together
        for(int LB = 0; LB < N; LB += (mergeSz + mergeSz)){         // LB is the lower bound of the LHS array
            if (LB + mergeSz >= N){
                // LHS array size extends past the end of the workSpace array
                break;
            }
            
            if (LB + mergeSz * 2 >= N){
                // RHS array size extends past the end of the workSpace array
                // Modify size of the RHS array
                merge(&workSpace[LB], mergeSz, &workSpace[LB + mergeSz], N - LB - mergeSz);
                break;
            }
            merge(&workSpace[LB], mergeSz, &workSpace[LB + mergeSz], mergeSz);
            // LB = index of arrayA
            // mergeSz = size of the arrays being merged
            // LB + mergeSz = index of arrayB
        }
    }
}

void MergeSort::iterativeSort(){
    itMergeSort(dataToSort);
}

void MergeSort::recursiveSort(){
    recMergeSort(dataToSort, 0, sizeDataToSort - 1);
}

bool MergeSort::isSorted(){
    // Check sort status of array
    for(int i = 0; i < sizeDataToSort-1; i++)
        if (dataToSort[i] > dataToSort[i + 1])
            // Elements are not sorted
            return false;
    // Elements are sorted
    return true;
}







