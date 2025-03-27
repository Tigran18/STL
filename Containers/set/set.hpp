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
            friend bool check(const set<T>& obj, T el){
                for(const auto& item : obj.m_set){
                    if(item == el){
                        return false;
                    }
                }
                return true;
            }

            set() = default;

            set(std::initializer_list<T> init){
                for(auto& el : init){
                    if(check(*this, el)){
                        m_set.push_back(el);
                    }
                }
                std::sort(m_set.begin(), m_set.end());
            }

            set(const set& other)=default;

            set(set&& other)noexcept{
                m_set=std::move(other.m_set);
            }

            set& operator=(const set& other){
                if(this!=&other){
                    m_set=other.m_set;
                }
                return *this;
            }

            set& operator=(set&& other)noexcept{
                if(this!=&other){
                    m_set=std::move(other.m_set);
                }
                return *this;
            }

            auto begin(){
                return m_set.begin();
            }
            
            auto begin()const{
                return m_set.begin();
            }
            
            auto end(){
                return m_set.end();
            }
            
            auto end()const{
                return m_set.end();
            }
    };
}

