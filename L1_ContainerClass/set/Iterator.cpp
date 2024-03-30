#include "Iterator.h"
#include <stdexcept>


/* Полезное */
template <typename T>
bool Iterator<T>::is_end()
{
    if (this->cur_node == nullptr)
        return true;
    return false;
}

template <typename T>
T Iterator<T>::value()
{
    if (this->is_end())
        throw std::out_of_range("Попытка выйти за пределы коллекции");

    return this->cur_node->content;
}

template <typename T>
node<T>* Iterator<T>::get_object()
{
    return this->cur_node;
}

/* Перемещение */
template <typename T>
Iterator<T> Iterator<T>::next()
{
    if (this->is_end())
        throw std::out_of_range("Попытка выйти за пределы коллекции");
    this->cur_node = this->cur_node->next;

    return *this;
}

/* Перегрузка операций */
template <typename T>
T& Iterator<T>::operator* ()
{
    return this->value();
}

template <typename T>
Iterator<T>& Iterator<T>::operator++ ()
{
    if (this->is_end())
        throw std::out_of_range("Попытка выйти за пределы коллекции");
    this->cur_node = this->cur_node->next;

    return *this;
}

template <typename T>
bool Iterator<T>::operator== (Iterator<T>& b)
{
    return this->cur_node == b.cur_node;
}

template <typename T>
bool Iterator<T>::operator!= (Iterator<T>& b)
{
    return this->cur_node != b.cur_node;
}

/* Деструктор */
template <typename T>
Iterator<T>::~Iterator() {}
