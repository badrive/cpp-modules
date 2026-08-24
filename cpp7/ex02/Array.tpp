#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(0)
{
	_data = new T[n]();
	_size = n;

}

template <typename T>
Array<T>::Array(Array const &src) : _data(NULL), _size(0)
{
	_size = src._size;
	_data = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = src._data[i];
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		delete[] _data;
		_size = rhs._size;
		_data = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = rhs._data[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T	&Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (_data[i]);
}

template <typename T>
T const	&Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (_data[i]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <typename T>
char const	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Array: index out of bounds");
}

#endif
