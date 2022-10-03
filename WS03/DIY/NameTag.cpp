#include <iostream>
#include "NameTag.h"
#include "Utils.h"
namespace sdds {
    NameTag n;
    void NameTag::set(const char* name) {
        strcpy(n.name, name, 50);
    }

    char* NameTag::getName() {
        return name;
    }
}