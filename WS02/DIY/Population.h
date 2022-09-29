#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
    struct Population {
        char* m_code;
        int m_figure;
    };
    bool load(const char filename[]);
    bool load(Population& p);
    void display();
    void deallocateMemory();
    void sortPopulation();
}
#endif // SDDS_POPULATION_H_