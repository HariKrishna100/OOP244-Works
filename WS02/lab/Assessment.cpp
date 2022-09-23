#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
#include "Utils.h"
namespace sdds {
    bool read(int& value, FILE* fptr) {
        return fscanf(fptr, "%d", &value) == 1;
    }

    bool read(double& value, FILE* fptr) {
        return fscanf(fptr, "%lf", &value) == 1;
    }

    bool read(char* cstr, FILE* fptr) {
        return fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
    }

    bool read(Assessment& asmnt, FILE* fptr) {
        double mark{};
        char str[61]{};

        read(mark, fptr);
        read(str, fptr);
        if (mark && str)
        {
            asmnt.m_mark = new double;
            asmnt.m_title = new char[60 + 1];
            *asmnt.m_mark = mark;
            strcpy(asmnt.m_title, str);
        }
        return mark;
    }

    void freeMem(Assessment*& aptr, int size) {

    }

    int read(Assessment*& aptr, FILE* fptr) {
        int* array = nullptr;
        int num, i;
        read(num, fptr);
        array = new int[num];

        for (i = 0; i < num; i++)
        {
            read(aptr[i], fptr);
        }
        return num;
    }
}