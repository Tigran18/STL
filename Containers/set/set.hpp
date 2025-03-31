#pragma once
#include <memory>
#include <vector>
#include <utility>
#include <algorithm>

namespace my{
    template <typename T>
    class set{
        private:
            std::vector<T> m_set;
        public:
            set();

            set(std::initializer_list<T> init);
            
            set(const set& other);

            set(set&& other)noexcept;

            set& operator=(const set& other);

            set& operator=(set&& other)noexcept;

            auto begin();
            
            auto begin()const;
            
            auto end();
            
            auto end()const;

            friend bool check(const set<T>& obj, T el){
                for(const auto& item : obj.m_set){
                    if(item == el){
                        return false;
                    }
                }
                return true;
            }
            
    };
}

#include "set.tpp"