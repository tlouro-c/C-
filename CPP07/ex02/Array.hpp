#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <vector>

typedef unsigned int uint;

template<typename T>
class Array {
public:
	uint size() const
	{
		return (_size);
	}
	Array()
	{
		_arrayBeg = new T[0]();
		_size = 0;
	}
	~Array()
	{
		delete[] _arrayBeg;
	}
	Array(const Array& other)
	{
		if (this != &other)
			*this = other;
	}
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] _arrayBeg;
			_arrayBeg = new T[other._size]();
			_size = other._size;
			for (int i = 0; i < _size; i++)
				_arrayBeg[i] = other._arrayBeg[i];
		}
		return (*this);
	}
	Array(uint size)
	{
		_arrayBeg = new T[size]();
		_size = size;
	}
	T& operator[](uint index)
	{
		if (index >= _size || index < 0)
			throw IndexOutOfBounds();
		return (_arrayBeg[index]);
	}
	class IndexOutOfBounds : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("array[] index out of bounds");
			}
	};
private:
	T* _arrayBeg;
	uint _size;
};

#endif
