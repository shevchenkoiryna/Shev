#include "Queue.h"

Queue::Queue(int capacity)
{
	_capacity = capacity;
	_arr = new int[_capacity];
	_count = 0;
}

Queue::~Queue()
{
	delete[] _arr;
	_arr = nullptr;
}

void Queue::add(int c)
{
	if (!isFull())
		_arr[_count++] = c;
}

int Queue::extract()
{
	if (!isEmpty()) {
		int temp = _arr[0];

		for (int i = 1; i < _count; i++)
			_arr[i - 1] = _arr[i];

		--_count;

		// для кольцевой очереди
		//--_count; // удалять
		//_arr[_count - 1] = temp;

		return temp;
	}

	return -1;
}

void Queue::clear()
{
	_count = 0;
}

bool Queue::isEmpty()
{
	return _count == 0;
}

bool Queue::isFull()
{
	return _count == _capacity;
}

int Queue::getCount()
{
	return _count;
}

void Queue::show()
{
	std::cout << "------------------\n";
	for (int i{}; i < _count; i++)
		std::cout << _arr[i] << " ";
	std::cout << "\n------------------\n";
}
