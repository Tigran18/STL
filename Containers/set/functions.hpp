#include "set.hpp"

template <typename T>
bool my::set<T>::check(const set<T>& obj, T el){
    for(const auto& item : obj.m_set){
        if(item == el){
            return false;
        }
    }
    return true;
}