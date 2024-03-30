#include "set.h"
#include <stdexcept>
#include <iostream>


template <class T>
Iterator<T>::Iterator(const set<T>& container_obj) : cur_node(container_obj.get_first()) {}

/* Конструкторы */
template <class T>
set<T>::set() : first(nullptr), last(nullptr) {}

template <class T>
set<T>::set(const set<T>& s) : first(nullptr), last(nullptr)
{
    for (Iterator<T> iterator = s.iterator_begin(); !iterator.is_end(); ++iterator)
        this->add(iterator.value());
}

template <class T>
set<T>::set(set<T>&& s) : first(s.get_first()), last(s.get_last())
{
    s.first = nullptr;
    s.last = nullptr;
}

template <class T>
set<T>::set(std::initializer_list<T> lst) : first(nullptr), last(nullptr)
{
    try {
        for (const T& value : lst)
            this->add(value);
    } catch (std::invalid_argument& e) {
        this->clear();
        throw e;
    }
}

/* Полезное */
template <class T>
int set<T>::get_length() const
{
    int i = 0;
    for (Iterator<T> iterator = this->iterator_begin(); !iterator.is_end(); ++iterator)
        i++;

    return i;
}

template <class T>
bool set<T>::contains(const T& elem) const
{
    for (Iterator<T> iterator = this->iterator_begin(); !iterator.is_end(); ++iterator)
        if (iterator.value() == elem)
            return true;
    return false;
}

template <class T>
T* set<T>::to_array() const
{
    T* array = new T[this->get_length()];
    int i = 0;
    for (Iterator<T> iterator = this->iterator_begin(); !iterator.is_end(); ++iterator) {
        array[i] = iterator.value();
        i++;
    }

    return array;
}

/* Получение итераторов */
template <class T>
Iterator<T> set<T>::iterator_begin() const
{
    Iterator<T> iterator(*this);

    return iterator;
}

template <class T>
Iterator<T> set<T>::iterator_end() const
{
    Iterator<T> iterator(*this);

    for (iterator = this->iterator_begin(); !iterator.is_end(); ++iterator);

    return iterator;
}

/*        Getter'ы        */
template <class T>
node<T>* set<T>::get_first() const
{
    return this->first;
}

template <class T>
node<T>* set<T>::get_last() const
{
    return this->last;
}

/* Манипуляции с размером */
template <class T>
void set<T>::add(const T& elem)
{
    if (!this->contains(elem)) {
        node<T>* newNode = new node<T>;
        newNode->content = elem;
        newNode->next = nullptr;

        if (this->first == nullptr)
            this->first = newNode;
        else
            this->last->next = newNode;
        this->last = newNode;
    }
    else
        throw std::invalid_argument("Cannot add dublicate values");
}

template <class T>
void set<T>::remove(const T& elem)
{
    if (this->contains(elem)) {
        node<T>* previous = this->first;
        node<T>* current = this->first;

        if (current->content != elem) {
            while (current->content != elem) {
                previous = current;
                current = previous->next;
            }
            if (current->next == nullptr)
                this->last = previous;
            previous->next = current->next;
            delete current;
        }
        else {
            this->first = current->next;
            if (this->first == nullptr)
                this->last = nullptr;
            delete current;
        }
    }
    else
        throw std::invalid_argument("Element does not in set");
}

template <class T>
void set<T>::clear()
{
    if (this->first != nullptr) {
        node<T>* current = this->first;
        while (this->first != nullptr) {
            this->first = current->next;
            delete current;
            current = this->first;
        }
        this->last = nullptr;
    }
}

/* Операции множества */
template <class T>
set<T>& set<T>::set_union(const set<T>& s)
{
    *this = *this + s;

    return *this;
}

template <class T>
set<T>& set<T>::set_intersection(const set<T>& s)
{
    *this = *this * s;

    return *this;
}

template <class T>
set<T>& set<T>::set_substract(const set<T>& s)
{
    *this = *this / s;

    return *this;
}

/* Перегрузка операций */
template <class T>
set<T>& set<T>::operator= (const set<T>& s)
{
    if (this != &s) {
        this->clear();
        for (Iterator<T> i = s.iterator_begin(); !i.is_end(); ++i)
            this->add(i.value());
    }

    return *this;
}

template <class T>
set<T>& set<T>::operator+= (const set<T>& s)
{
    this->set_union(s);
    return *this;
}

template <class T>
set<T>& set<T>::operator*= (const set<T>& s)
{
    this->set_intersection(s);
    return *this;
}

template <class T>
set<T>& set<T>::operator/= (const set<T>& s)
{
    this->set_substract(s);
    return *this;
}

/*   Функции  друзья   */
template <class _T>
std::ostream& operator<< (std::ostream& os, const set<_T>& lst)
{
    if (lst.get_length() == 0) {
        os << "Set is empty";
        return os;
    }
    os << "[ ";
    for (Iterator<_T> iterator = lst.iterator_begin(); !iterator.is_end(); ++iterator)
            os << iterator.value() << " ";
    os << "]";

    return os;
}

template <class _T>
set<_T> operator+ (const set<_T>& s1, const set<_T>& s2)
{
    set<_T> s_union(s1);

    for (Iterator<_T> iterator = s2.iterator_begin(); !iterator.is_end(); ++iterator)
        if (!s1.contains(iterator.value()))
            s_union.add(iterator.value());

    return s_union;
}

template <class _T>
set<_T> operator* (const set<_T>& s1, const set<_T>& s2)
{
    set<_T> s_intersection;

    for (Iterator<_T> iterator = s2.iterator_begin(); !iterator.is_end(); ++iterator)
        if (s1.contains(iterator.value()))
            s_intersection.add(iterator.value());

    return s_intersection;
}

template <class _T>
set<_T> operator/ (const set<_T>& s1, const set<_T>& s2)
{
    set<_T> s_substract;

    for (Iterator<_T> iterator = s1.iterator_begin(); !iterator.is_end(); ++iterator)
        if (!s2.contains(iterator.value()))
            s_substract.add(iterator.value());

    for (Iterator<_T> iterator = s2.iterator_begin(); !iterator.is_end(); ++iterator)
        if (!s1.contains(iterator.value()))
            s_substract.add(iterator.value());

    return s_substract;
}

/* Деструктор */
template <class T>
set<T>::~set<T>()
{
    this->clear();
}
