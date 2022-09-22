#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
namespace sdds {
    bool read(int& value, FILE* fptr) {
        fscanf(fptr, "%d", &value);
        return &value;
    }

    bool read(double& value, FILE* fptr) {
        fscanf(fptr, "%lf", &value);
        return &value;
    }

    bool read(char* cstr, FILE* fptr) {
        fscanf(fptr, ",%60[^\n]\n", cstr);
        return cstr;
    }

    bool read(Assessment& asmnt, FILE* fptr) {
       
    }

    void freeMem(Assessment*& aptr, int size) {

    }

    int read(Assessment*& aptr, FILE* fptr) {
        
    }
}