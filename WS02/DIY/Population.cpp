#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Population.h"
#include "File.h"
using namespace std;
namespace sdds {
    Population* p;
    int count;

    bool load(Population& p) {
        bool success = false;
        char poCode[150];
        if (true) {
            success = read(poCode);
            success = success && read(p.m_figure);
            p.m_code = new char[strlen(poCode) + 1];
            strcpy(p.m_code, poCode);
        }
        return success;
    }

    bool load(const char filename[]) {
        bool success = false;
        if (openFile(filename)) {
            success = true;
            count = noOfRecords();
            p = new Population[count];
            for (int i = 0; success && i < count; i++) {
                success = load(p[i]);
            }
            if (!success) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            closeFile();
        }
        return success;
    }

    void display() {
        int j = count, i = 0, totalPopulation = 0;

        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sortPopulation();

        while (j != 0) {
            cout << i + 1 << "- " << p[i].m_code << ":  " << p[i].m_figure << endl;
            totalPopulation += p[i].m_figure;
            i++, j--;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopulation << endl;
    }

    void sortPopulation() {
        int i, j;
        struct Population swap;
        for (i = count - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (p[j].m_figure > p[j + 1].m_figure) {
                    swap = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = swap;
                }
            }
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < count; i++) {
            delete[] p[i].m_code;
            p[i].m_code = nullptr;
        }
        delete[] p;
    }

}