#pragma once

namespace my{
    class algorithms{
        private:
        
        public:
            algorithms()=delete;
            //copy constructors deleting
            algorithms(const algorithms& other)=delete;
            algorithms& operator=(const algorithms& other)=delete;
            //move constructors deleting
            algorithms(algorithms&& other)noexcept=delete;
            algorithms& operator=(algorithms&& other)noexcept=delete;

            static sort(){

            }
            
    };
}

#include "algorithms.tpp"