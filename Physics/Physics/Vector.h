#pragma once
#include <iostream>
#include <string>

template <typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector<T>& other);
	Vector(T initialValue);
	Vector(std::initializer_list<T> initialValue, const bool empty = false);
	~Vector();

	void push_back(const T& value);
	const T& at(size_t index) const;
	size_t size() const;
	void pop_back();
	void removeAt(size_t index);
	std::string toString() const;
private:
	T* elements;
	size_t capacity;
	size_t currentSize;

	void resize();
	void downsize();
	size_t getCapacity() const;
	size_t getCurrentSize() const;
	void setCapacity(size_t capacity);
	void setCurrentSize(size_t currentSize);
};

template <typename T>
Vector<T>::Vector()
	:Vector({})
{

}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->setCapacity(other.size());
	this->setCurrentSize(0);
	this->elements = new T[this->getCapacity() == 1 ? 2 : this->getCapacity()];

	for (size_t i = 0; i < other.getCurrentSize(); i++)
	{
		this->push_back(other.at(i));
	}
}

template <typename T>
Vector<T>::Vector(T initialValue)
	:Vector<T>({ initialValue })
{
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> initialValue, const bool empty)
{
	size_t sizeWithDistance = std::distance(initialValue.begin(), initialValue.end());
	this->setCapacity(sizeWithDistance);
	this->setCurrentSize(0);
	this->elements = new T[this->getCapacity() == 1 ? 2 : this->getCapacity()];

	if (!empty)
	{
		for (T value : initialValue)
		{
			this->push_back(value);
		}
	}
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] elements;
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
	resize();

	elements[this->getCurrentSize()] = value;
	this->setCurrentSize(this->getCurrentSize() + 1);
}

template<typename T>
const T& Vector<T>::at(size_t index) const
{
	if (index < this->getCurrentSize())
	{
		return elements[index];
	}
	else
	{
		throw "Index out of bounds";
	}
}

template<typename T>
size_t Vector<T>::size() const
{
	return this->getCurrentSize();
}

template<typename T>
void Vector<T>::pop_back()
{
	if (currentSize > 0) {
		this->setCurrentSize(this->getCurrentSize() - 1);
		downsize();
	}
}

template<typename T>
void Vector<T>::removeAt(size_t index)
{
	if (index < this->getCurrentSize()) {
		for (size_t i = index; i < this->getCurrentSize() - 1; ++i) {
			elements[i] = elements[i + 1];
		}
		this->setCurrentSize(this->getCurrentSize() - 1);
		downsize();
	}
	else {
		throw "Index out of bounds";
	}
}

template<typename T>
inline std::string Vector<T>::toString() const
{
	std::string s;
	s += "[";
	for (size_t i = 0; i < currentSize; ++i) {
		if (std::is_class<T>::value)
		{
			s += elements[i].toString();
		}
		else{
			s += std::to_string(elements[i]);
		}
		if (i < currentSize - 1) {
			s += ", ";
		}
	}
	s += "]";
	return s;
}

template<typename T>
void Vector<T>::resize()
{
	if (this->getCurrentSize() == this->getCapacity())
	{
		this->setCapacity(this->getCapacity() * 2);
		T* newElements = new T[this->getCapacity()];

		for (size_t i = 0; i < this->getCurrentSize(); ++i) {
			newElements[i] = elements[i];
		}

		delete[] elements;
		this->elements = newElements;
	}
}

template<typename T>
void Vector<T>::downsize()
{
	if (this->getCurrentSize() < this->getCapacity() / 2) {
		this->setCapacity(this->getCapacity() / 2);
		T* newElements = new T[this->getCapacity()];

		for (size_t i = 0; i < this->getCurrentSize(); ++i) {
			newElements[i] = elements[i];
		}

		delete[] elements;
		elements = newElements;
	}
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
size_t Vector<T>::getCurrentSize() const
{
	return this->currentSize;
}

template<typename T>
void Vector<T>::setCapacity(size_t capacity)
{
	this->capacity = capacity;
}

template<typename T>
void Vector<T>::setCurrentSize(size_t currentSize)
{
	this->currentSize = currentSize;
}