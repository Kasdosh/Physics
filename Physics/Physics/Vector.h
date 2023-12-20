#pragma once

#include <iostream>

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