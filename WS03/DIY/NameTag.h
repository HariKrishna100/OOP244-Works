#ifndef SDDS_NameTag_H_
#define SDDS_NameTag_H_
namespace sdds {
    class NameTag {
    private:
        char name[51];
    public:
        void set(const char* name);
        char* getName();
    };
}
#endif // !SDDS_NameTag_H_
