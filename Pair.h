
#ifndef UNTITLED_PAIR_H
#define UNTITLED_PAIR_H
#include <string>
#include <utility>
#include <iostream>
using namespace std;
class Pair {

private:
int m_priority;
string m_data;
Pair* m_ptr;
int m_index = -1;


public:
    Pair(int priority, string data, Pair* p = nullptr): m_priority(priority), m_data(data), m_ptr(p) {}
    Pair();

    Pair(const Pair& p);

    Pair(Pair&& p);

    const Pair& operator= (const Pair& p);

    const Pair& operator= (Pair&& p);

    void setPriority(int p){m_priority = p;};
    void setData(std::string d){m_data = std::move(d);};
    void setIndex(int i) { m_index = i; };
    void setPointer(Pair* p) { m_ptr = p; };

    int getPriority() const{return  m_priority;};
    std::string getData(){return m_data;};
    int getIndex() const { return  m_index; };
    Pair* getPointer() const { return m_ptr; };

    friend ostream& operator<<(ostream& os, const Pair& p);


};


#endif //UNTITLED_PAIR_H
