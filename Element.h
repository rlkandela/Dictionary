#ifndef __CPPELEM__
#define __CPPELEM__
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
template<class J>
class Element{
private:
    J value;
    bool check;
public:
    Element();
    Element(const Element<J>& e);
    Element(J e);
    virtual ~Element();
    Element<J>& operator=(J e);
    Element<J>& operator=(Element<J> e);
    bool operator==(J e);
    bool operator==(Element<J> e);
    template<typename B> friend std::ostream& operator<< (std::ostream& os, Element<B> e);
    bool hasValue()const;
    void quitValue();
    void setValue(J e);
    J get()const;
};
#include "Element.tcc"
#endif