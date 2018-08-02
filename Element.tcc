template<class J>
Element<J>::Element(){
    check=false;
}

template<class J>
Element<J>::Element(const Element<J>& e){
    check=e.hasValue();
    value=e.get();
}

template<class J>
Element<J>::Element(J e){
    check=true;
    value=e;
}

template<class J>
Element<J>::~Element(){}

template<class J>
Element<J>& Element<J>::operator=(J e){
    this->check=true;
    this->value=e;
    return (*this);
}

template<class J>
Element<J>& Element<J>::operator=(Element<J>e){
    this->value=e.get();
    this->check=e.hasValue();
    return (*this);
}

template<class J>
bool Element<J>::operator==(J e){
    if(check){
        if(value==e){
            return true;
        }
    }
    return false;
}

template<class J>
bool Element<J>::operator==(Element<J> e){
    if(value == e.get()){
        if(check==e.hasValue()){
            return true;
        }
    }
    return false;
}

template<typename B>
std::ostream& operator<<(std::ostream& os, Element<B> e){
    if(e.check){
        os<<e.get();
    }else{
        os<<"NULL";
    }
    return os;
}

template<class J>
bool Element<J>::hasValue()const{
     return check;
}

template<class J>
void Element<J>::quitValue(){
    check=false;
}

template<class J>
void Element<J>::setValue(J e){
    check=true;
    value=e;
}

template<class J>
J Element<J>::get()const{
    return value;
}