#pragma once
#include <iostream>
#include <fstream>

class MyString
{
public:
    MyString();
    MyString(const char* data);
    explicit MyString(size_t stringLength);

    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    MyString(MyString&&);
    MyString& operator=(MyString&&);
    ~MyString();

    size_t getCapacity() const;
    size_t getSize() const;

    const char* c_str() const;

    MyString& operator+=(const MyString& other);

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
    friend std::istream& operator>>(std::istream& is, MyString& ref);
    void saveToBinary(std::ofstream& ofs) const;
    void loadFromBinary(std::ifstream& ifs);
    MyString substr(unsigned startIndex, unsigned len) const;
    MyString& operator+=(char ch);

private:
    void resize(unsigned newAllocatedDataSize);

    void free();
    void copyFrom(const MyString& other);
    void moveFrom(MyString&&);

    char* _data;
    size_t _size;
    size_t _allocatedDataSize;
};

MyString operator+(const MyString& lhs, const MyString& rhs);

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);

