#pragma once
#include <memory>
#include <utility>
#include <vector>

namespace my{
	template <typename T>
	class queue{
	private:
		std::vector<T> m_queue={};
	public:

		queue();

		queue(std::initializer_list<T> init);

		queue(const queue& other);

		queue(queue&& other)noexcept;

		queue& operator=(const queue& other);

		queue& operator=(queue&& other);

		std::size_t size();

		bool empty();

		void push(const T& value);

		void pop();

		void clear();

		T& front();

		const T& front()const;

		T& back();

		const T& back()const;
	};
}

#include "queue.tpp"