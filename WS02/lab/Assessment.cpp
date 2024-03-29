#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
#include "Utils.h"
namespace sdds {
    bool read(int& value, FILE* fptr) {
        return fscanf(fptr, "%d", &value);
    }

    bool read(double& value, FILE* fptr) {
        bool fail = false;
        if (fscanf(fptr, "%lf", &value) == 1) {
            fail = true;
        }
        return fail;
    }

    bool read(char* cstr, FILE* fptr) {
        return fscanf(fptr, ",%60[^\n]\n", cstr);
    }

    bool read(Assessment& asmnt, FILE* fptr) {
        double mark{};
        char str[61]{};
        int len;
        bool success = false;
        read(mark, fptr);
        read(str, fptr);

        len = strlen(str);

        success = read(mark, fptr) && read(str, fptr);

        if (success) {
            asmnt.m_mark = new double;
            asmnt.m_title = new char[len + 1];
            asmnt.m_mark = &mark;
            strcpy(asmnt.m_title, str);
        }
        return success;
    }

    void freeMem(Assessment*& aptr, int size) {
        for (int i = 0; i < size; i++) {
            delete[] aptr[i].m_mark;
            delete[] aptr[i].m_title;
            aptr[i].m_mark = nullptr;
            aptr[i].m_title = nullptr;
        }
        delete[] aptr;
        aptr = nullptr;
    }


    int read(Assessment*& aptr, FILE* fptr) {
        int num = 0, i, data = 0;
        int flag = 0;
        aptr = new Assessment[num];

        read(num, fptr);

        for (i = 0; flag == 0 && i < num; i++) {
            if (read(aptr[i], fptr)) {
                data++;
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        }
        if (data != num)
        {
            freeMem(aptr, data);
            data = 0;
        }
        return data;
    } 
}