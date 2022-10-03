#include <iostream>
#include "TagList.h"
namespace sdds {
    void TagList::set() {
        tags = nullptr;
        frame = 0;
        size = 0;
        fit = 0;
    }

    void TagList::set(int num) {
        cleanup();
        tags = new NameTag[num];
        fit = num;
    }

    void TagList::add(const NameTag& nt) {

    }

    void TagList::print() {

    }

    void TagList::cleanup() {
        delete[] tags;
        tags = nullptr;
    }
}