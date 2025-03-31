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

            bool empty() const{
                return m_set.empty();
            }

            auto find(const T& data)const{
                for(auto it=m_set.begin(); it!=m_set.end(); ++it){
                    if(data==*it){
                        return it;
                    }
                }
                return m_set.end();
            }

            std::size_t size()const{
                return m_set.size();
            }

            void insert(const T& data){
                m_set.push_back(data);
                std::sort(m_set.begin(), m_set.end());
            }

            void erase(const T& data){
                std::size_t i=0;
                for(auto it=m_set.begin(); it!=m_set.end(); ++it){
                    if(*it==data){
                        m_set.erase(m_set.begin()+i);
                    }
                    i++;
                }
            }

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