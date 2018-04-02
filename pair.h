#ifndef PAIR_H
#define PAIR_H

#include <utility>

using namespace std;

//Tempplate
template <class T>
class Pair{
public:
    Pair(T itemOne, T itemTwo);
    Pair();

    T getFirst() const;
    T getSecond() const;

    void setFirst(T first);
    void setSecond(T second);
private:
    T first;
    T second;
};

template <typename T>
Pair<T>::Pair(T fst, T snd): first{fst}, second{snd} {
}

template<class T>
Pair<T>::Pair(){

}

template<class T>
T Pair<T>::getFirst() const{
    return first;
}

template<class T>
T Pair<T>::getSecond() const{
    return second;
}

template<class T>
void Pair<T>::setFirst(T first){
    this->first = first;
}

template<class T>
void Pair<T>::setSecond(T second){
    this->second = second;
}

#endif // PAIR_H
