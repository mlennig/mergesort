//
//  Mim_Lennig_A3_testcases.cpp
//  Mim_Lennig_A3
//
//  Created by Miriam Lennig on 2016-10-09.
//  Copyright © 2016 Mim Lennig. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Mim_Lennig_A3_classes.hpp"
#include <vector>
#include <cassert>

using namespace std;

void createRandFile(string fileName){
    // Create a file of a random # of random #s
    ofstream oFile;
    oFile.open(fileName);
    
    for (int i = 0; i < 2 + rand() % 100000; i ++){
        double randNum = rand();
        
        while (randNum == 0)
            randNum = rand();
        
        oFile << 1000 * ( rand() > RAND_MAX / 2. ? 1. : -1. ) * rand() / randNum  << endl;
    }
    
    oFile.close();
}

void createRandFile(string fileName, int numElements){
    ofstream oFile;
    oFile.open(fileName);
    
    for (int i = 0; i < numElements; i ++){
        double randNum = rand();
        
        while (randNum == 0)
            randNum = rand();
        
        oFile << 1000 * ( rand() > RAND_MAX / 2. ? 1. : -1. ) * rand() / randNum  << endl;
    }
    
    oFile.close();
}

int main() {
    clock_t time0, time1;
    vector<clock_t> ticks;
    vector<int> nElements;
    
    srand(unsigned(time(NULL)));
    
    cout << "createRandFile(\"sortinput.txt\")\n" << endl;
    createRandFile("sortinput.txt");
    
    cout << "MergeSort rms = MergeSort(\"sortinput.txt\")" << endl << endl;
    MergeSort rms = MergeSort("sortinput.txt");
    assert(!rms.isSorted());    // Generate a runtime error if rms is already sorted
    
    // Print the sort status of rms
    if (rms.isSorted())
        cout << "rms is sorted." << endl;
    else
        cout << "rms is not sorted." << endl << endl;
    
    cout << "MergeSort ims = MergeSort(\"sortinput.txt\")" << endl << endl;
    MergeSort ims = MergeSort("sortinput.txt");
    assert(!ims.isSorted());    // Generate a runtime error if ims is already sorted
    
    if (ims.isSorted())
        cout << "ims is sorted." << endl;
    else
        cout << "ims is not sorted." << endl << endl;
    
    cout << "rms.print();" << endl << endl;
    rms.print();
    cout << endl;
    
    cout << "rms.recursiveSort();" << endl;
    
    time0 = clock();
    rms.recursiveSort();
    time1 = clock();
    assert(rms.isSorted());
    
    clock_t cpuCycles = time1 - time0;
    cout << "clock_t cpuCycles = time1 - time0:" << endl;
    cout << cpuCycles << " ticks = " << 1000000 * cpuCycles / CLOCKS_PER_SEC << " us" << endl << endl;
    
    if (rms.isSorted())
        cout << "rms is sorted." << endl;
    else
        cout << "rms is not sorted." << endl << endl;
    
    cout << "rms.print();" << endl << endl;
    rms.print();
    cout << endl;
    
    cout << "rms.writeResults2File(\"sortoutput.txt\")" << endl << endl;
    rms.writeResults2File("sortoutput.txt");

    
    cout << "ims.iterativeSort();" << endl;
    
    time0 = clock();
    ims.iterativeSort();
    time1 = clock();
    assert(ims.isSorted());
    
    cout << "cpuCycles:" << endl;
    cout << cpuCycles << " ticks = " << 1000000 * cpuCycles / CLOCKS_PER_SEC << " us" << endl << endl;
    
    if (ims.isSorted())
        cout << "ims is sorted." << endl;
    else
        cout << "ims is not sorted." << endl << endl;
    
    cout << "ims.print();" << endl << endl;
    ims.print();
    
    cout << endl;
    
    ofstream rmsFile;
    rmsFile.open("rmsValues.txt");
    rmsFile << ",Recursive Merge Sort" << endl;
    ofstream imsFile;
    imsFile.open("imsValues.txt");
    imsFile << ",Iteratitive Merge Sort" << endl;
    
    cout << "Sorting 1000, 11000, 21000, ... , 71000, 81000, 91000 elements using the recursive merge sort and then the iterative merge sort. Recording the time it takes to sort each set of elements. Creating two files, rmsValues.txt and imsValues.txt, to store the number of elements and corresponding elapsed time taken to sort via each method." << endl << endl;
    
    for (int i = 1000; i <= 91000; i += 10000){
        createRandFile("sortinput.txt", i);
        
        rms = MergeSort("sortinput.txt");
        assert(!rms.isSorted());
        
        time0 = clock();
        rms.iterativeSort();
        time1 = clock();
        assert(rms.isSorted());
        
        rmsFile << i << ", " << time1 - time0 << endl;
        
        ims = MergeSort("sortinput.txt");
        assert(!ims.isSorted());
        
        time0 = clock();
        ims.iterativeSort();
        time1 = clock();
        assert(ims.isSorted());
        
        imsFile << i << ", " << time1 - time0 << endl;
        
    }

    rmsFile.close();
    imsFile.close();

}
