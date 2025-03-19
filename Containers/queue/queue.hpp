#pragma once
#include <memory>
#include <utility>
#include <vector>

namespace my{
	template <typename T>
	class queue{
	private:
		std::vector<T> m_queue={};
		std::size_t m_size=0;
	public:

		queue();

		queue(std::initializer_list<T> init);

		std::size_t size();

		bool empty();

		void push(const T& value);

		void pop();

		void clear();

		T& front()const;

		T& back()const;

	};
}

#include "queue.tpp"