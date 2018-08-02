#ifndef __CPPDICT__
#define __CPPDICT__
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Element.h"
template <class T, class U>
class Dictionary{
private:
    std::vector< Element<T> > KeyV;
    std::vector< Element<U> > ValueV;
    bool constructingError;
public:
    Dictionary();
    Dictionary(const Dictionary<T,U>& dic);
    Dictionary(T key,U value);
    Dictionary(std::vector<T> v1,std::vector<U> v2);
    virtual ~Dictionary();
    Element<U>& operator [](T Key);
    Dictionary<T,U> operator+(Dictionary<T,U> dic);
    Dictionary<T,U>& operator=(Dictionary<T,U> dic);
    bool operator==(Dictionary<T,U> dic);
    template <typename V, typename W> friend std::ostream& operator<< (std::ostream& os, const Dictionary<V,W>& dic);
    std::vector<T> getKeyV()const;
    std::vector<U> getValueV()const;
    void clear();
    bool checkConstructingError();
    void resetConstructingError();
};
#include "Dictionary.tcc"
#endif