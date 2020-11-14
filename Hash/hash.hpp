#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <string>

template <typename T>
struct NODE
{
    std::string key;
    T data;
};

template <typename T>
class HASH
{
private:
    NODE<T> *table;
    bool *deleted;
    int hashing(string key);

public:
    HASH() : table(0), deleted(0){};
    bool init(int n);
    T search(string key);
    bool add(string key, T data);
    bool deleteData(string key);
};

#include "hash.cpp"

#endif