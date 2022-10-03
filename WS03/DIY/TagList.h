#ifndef SDDS_TagList_H_
#define SDDS_TagList_H_
#include "NameTag.h"
namespace sdds {
    class TagList {
    private:
        NameTag* tags;
        unsigned int frame;
        unsigned int size;
        unsigned int fit;
    public:
        void set();
        void set(int num);
        void add(const NameTag& nt);
        void print();
        void cleanup();
    };
}
#endif // !SDDS_TagList_H_
