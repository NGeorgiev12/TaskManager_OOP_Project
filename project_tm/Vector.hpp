#pragma once
#include <fstream>
template <typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	Vector(Vector<T>&&);
	Vector<T>& operator=(Vector<T>&&);
	~Vector();

	void pushBack(const T& toAdd);
	void pushBack(T&&);
	void popBack();
	void insert(const T& str, unsigned index);
	void insert(T&& str, unsigned index);
	void erase(unsigned index);
	bool empty() const;
	void readFromBinary(std::ifstream& ifs, size_t size);
	const T& operator[](size_t) const;
	T& operator[](size_t);
	size_t getSize() const;
	friend std::ostream& operator<<(std::ostream&, const Vector<T>&);
	//friend std::istream& operator>>(std::istream&, Vector<T>&);

private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 8;

	void free();
	void copyFrom(const Vector&);
	void moveFrom(Vector<T>&&);
	void resize(size_t newCap);
};

static unsigned roundToPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

template <typename T>
Vector<T>::Vector()
{
	data = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	free();
}

template <typename T>
void Vector<T>::pushBack(const T& toAdd)
{

	if (size == capacity)
		resize(roundToPowerOfTwo(size + 1));

	size++;
	data[size - 1] = toAdd;
}

template <typename T>
void Vector<T>::pushBack(T&& other)
{
	if (size == capacity)
		resize(roundToPowerOfTwo(size + 1));

	size++;
	data[size - 1] = std::move(other);
}

template <typename T>
void Vector<T>::popBack()
{
	size--;
}

template <typename T>
void Vector<T>::insert(const T& str, unsigned index)
{
	if (index >= size)
		throw std::invalid_argument("Out of bounds");

	if (size == capacity)
		resize(roundToPowerOfTwo(size + 1));

	size++;

	for (int i = size - 2; i >= index; i--)
	{
		data[i + 1] = data[i];
	}

	data[index] = str;
}

template <typename T>
void Vector<T>::insert(T&& str, unsigned index)
{
	if (index >= size)
		throw std::invalid_argument("Out of bounds");

	if (size == capacity)
		resize(roundToPowerOfTwo(size + 1));

	for (int i = size - 1; i >= index; i--)
	{
		data[i + 1] = std::move(data[i]);
	}
	size++;

	data[index] = str;
}

template <typename T>
void Vector<T>::erase(unsigned index)
{
	if (index >= size)
		throw std::invalid_argument("Out of bounds");

	for (unsigned i = index; i < size; i++)
	{
		data[i + 1] = data[i];
	}
	size--;
}

template <typename T>
void Vector<T>::free()
{
	delete[] data;
	size = 0;
	capacity = 0;
	data = nullptr;
}

template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template <typename T>
void Vector<T>::moveFrom(Vector<T>&& other)
{
	data = other.data;
	other.data = nullptr;
	size = other.size;
	other.size = 0;
	capacity = other.capacity;
	other.capacity = 0;
}

template <typename T>
void Vector<T>::resize(size_t newCapacity)
{
	T* temp = new T[newCapacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = std::move(this->data[i]);
	}
	delete[] data;
	capacity = newCapacity;
	data = temp;
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
	return data[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
	return data[index];
}

template <typename T>
bool Vector<T>::empty() const
{
	return (size == 0);
}

template<typename T>
void Vector<T>::readFromBinary(std::ifstream& ifs, size_t size)
{
	// първо зануляваме вектора, после четем от файла
	free();
	capacity = roundToPowerOfTwo(size);
	data = new T[capacity];
	this->size = size;
	ifs.read(reinterpret_cast<char*>(data), sizeof(T) * size);
}

template <typename T>
size_t Vector<T>::getSize() const
{
	return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>&)
{
	for (int i = 0; i < Vector<T>.size; i++)
	{
		out << Vector<T>.data[i] << " ";
	}
	return out;
}

