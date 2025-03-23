#include <iostream>
#include "queue.hpp"

int main(){
	my::queue<int> q1{5, 7, 8, 10};
	my::queue<int> q2;
	q2=std::move(q1);
	std::cout<<"Size of q1 after moving: ";
	std::cout<<q1.size()<<std::endl;
	// try{
	// 	do{
	// 		std::cout<<q1.front()<<"  ";
	// 		q1.pop();
	// 	}while(q1.empty());
	// 	std::cout<<std::endl;
	// }
	// catch(const std::exception& ex){
	// 	std::cout<<ex.what()<<std::endl;
	// }
	std::cout<<"Printing the elements of q2: ";
	do{
		std::cout<<q2.front()<<"  ";
		q2.pop();
	}while(!q2.empty());
	std::cout<<std::endl;
	q2.push(5);
	std::cout<<q2.front()<<std::endl;
	q2.clear();
	try{
		std::cout<<q2.front()<<std::endl;
	}
	catch(const std::exception& ex){
		std::cout<<ex.what()<<std::endl;
	}
	return 0;
}
