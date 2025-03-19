#include <iostream>
#include "queue.hpp"


int main(){
	my::queue<int> q1{5, 7};
	std::cout<<q1.empty()<<"  "<<q1.size()<<std::endl;
	return 0;
}
