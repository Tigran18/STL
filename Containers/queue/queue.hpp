#pragma once
#include <memory>
#include <utility>
#include <initalizer_list>
#include <vector>

namespace my{
	class queue{
	private:
		std::vector<T> m_queue={};
		std::size_t m_size=0;
	public:

		queue();

		queue(std::initializer_list<std> init);

		std::size_t size();

		bool empty();

		void push(const T& value);

		void pop();

		void clear();

		T& front();

		T& back();

	};
}
