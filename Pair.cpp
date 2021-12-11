//
// Created by bar sela on 08/12/2021.
//

#include "Pair.h"
ostream& operator<<(ostream& os, const Pair& p)
{
    os << p.m_priority << ' ' << p.m_data << endl;
    return os;
}

Pair::Pair() {
    m_priority = 0;
    m_data = "s";
    m_ptr = nullptr;
    m_index = -1;
}

Pair::Pair(const Pair& p) {
    m_priority = p.m_priority;
    m_data = p.m_data;
    m_ptr = p.m_ptr;
    m_index = p.m_index;
}

Pair::Pair(Pair&& p)
{
    m_data = std::move(p.m_data);
    m_priority = p.m_priority;
    m_ptr = p.m_ptr;
    m_index = p.m_index;
}

const Pair& Pair::operator= (const Pair& p)
{
    if (this != &p)
    {
        m_data = p.m_data;
        m_priority = p.m_priority;
        m_ptr = p.m_ptr;
        m_index = p.m_index;
    }
    return *this;
}

const Pair& Pair::operator= (Pair&& p)
{
    if (this != &p)
    {
        m_data = std::move(p.m_data);
        m_priority = p.m_priority;
        m_ptr = p.m_ptr;
        m_index = p.m_index;
    }
    return *this;
}