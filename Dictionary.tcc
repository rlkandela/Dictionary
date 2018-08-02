template<class T, class U>
Dictionary<T,U>::Dictionary():KeyV(),ValueV(){constructingError=false;}

template<class T, class U>
Dictionary<T,U>::Dictionary(const Dictionary<T,U>& dic):KeyV(),ValueV(){
    std::vector<T> v1=dic.getKeyV();
    std::vector<U> v2=dic.getValueV();
    for(int i=0;i<v1.size();i++){
        KeyV.push_back(Element<T>(v1[i]));
        ValueV.push_back(Element<U>(v2[i]));
    }
    constructingError=false;
}

template<class T, class U>
Dictionary<T,U>::Dictionary(T key, U value):KeyV(),ValueV(){
    KeyV.push_back(Element<T> (key));
    ValueV.push_back(Element<U> (value));
    constructingError=false;
}

template<class T, class U>
Dictionary<T,U>::Dictionary(std::vector<T> v1, std::vector<U> v2):KeyV(),ValueV(){
    if(v1.size()==v2.size()){
        for(int i=0;i<v1.size();i++){
            KeyV.push_back(Element<T>(v1[i]));
            ValueV.push_back(Element<U>(v2[i]));
        }
        constructingError=false;
    }else{
        constructingError=true;
    }
}

template<class T,class U>
Dictionary<T,U>::~Dictionary(){
    KeyV.clear();
    ValueV.clear();
}

template<class T, class U>
Element<U>& Dictionary<T,U>::operator[](T key){
    for(int i=0;i<KeyV.size();i++){
        if(KeyV[i]==key){
            return ValueV[i];
        }
    }
    KeyV.push_back(Element<T>(key));
    ValueV.push_back(Element<U>());
    return ValueV[ValueV.size()-1];
}

template<class T, class U>
Dictionary<T,U> Dictionary<T,U>::operator+(Dictionary<T,U> dic){
    std::vector<T> v1=getKeyV();
    std::vector<U> v2=getValueV();
    std::vector<T> v3=dic.getKeyV();
    std::vector<U> v4=dic.getValueV();
    for(int i=0;i<v3.size();i++){
        bool found=false;
        bool error=false;
        int n1=0;
        for(int j=0;j<v1.size();j++){
            if(v3[i]==v1[j]){
                if(v4[i]!=v2[j]){
                    error=true;
                    n1=j;
                }else{
                    found=true;
                }
            }
        }
        if(!found){
            if(!error){
                v1.push_back(v3[i]);
                v2.push_back(v4[i]);
            }else{
                v1.erase(v1.begin()+n1);
                v2.erase(v2.begin()+n1);
            }
        }
    }
    return Dictionary<T,U>(v1,v2);
}

template<class T, class U>
Dictionary<T,U>& Dictionary<T,U>::operator=(Dictionary<T,U> dic){
    std::vector<T> v1=dic.getKeyV();
    std::vector<U> v2=dic.getValueV();
    this->clear();
    for(int i=0;i<v1.size();i++){
        (*this)[v1[i]].setValue(v2[i]);
    }
    return (*this);
}

template<class T, class U>
bool Dictionary<T,U>::operator==(Dictionary<T,U> dic){
    Dictionary<T,U> sum=(*this)+dic;
    if(dic.getKeyV().size()==sum.getKeyV().size()){
        std::vector<T> vec=dic.getKeyV();
        std::vector<T> vec2=sum.getKeyV();
        T e=vec[0];
        for(int i=0;i<vec.size();i++,e=vec[i]){
            bool found=false;
            T elem=vec2[0];
            for(int j=0;!found && j<vec2.size();j++,elem=vec2[j]){
                if(e==elem){
                    found=true;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
    return false;
}

template<typename V, typename W>
std::ostream& operator<<(std::ostream& os, const Dictionary<V,W>& dic){
    std::vector<V> v1=dic.getKeyV();
    std::vector<W> v2=dic.getValueV();
    for(int i=0;i<v1.size();i++){
        if(i){
            os<<" , ";
        }
        os<<"[ "<<v1[i]<<" : "<<v2[i]<<" ]";
    }
    return os;
}

template<class T, class U>
std::vector<T> Dictionary<T,U>::getKeyV() const{
    std::vector<T> ret;
    for(int i=0;i<KeyV.size();i++){
        if(ValueV[i].hasValue()){
            ret.push_back(KeyV[i].get());
        }
    }
    return ret;
}

template<class T, class U>
std::vector<U> Dictionary<T,U>::getValueV() const{
    std::vector<U> ret;
    for(int i=0;i<ValueV.size();i++){
        if(ValueV[i].hasValue()){
            ret.push_back(ValueV[i].get());
        }
    }
    return ret;
}

template<class T, class U>
void Dictionary<T,U>::clear(){
    KeyV.clear();
    ValueV.clear();
}

template<class T, class U>
bool Dictionary<T,U>::checkConstructingError(){
    return constructingError;
}

template<class T, class U>
void Dictionary<T,U>::resetConstructingError(){
    constructingError=false;
}