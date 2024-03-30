#ifndef SET_H
#define SET_H

#include <initializer_list>
#include <ostream>
#include "Iterator.h"

template <class T>
class Iterator;


template <class T>
class set
{
public:
    /* Конструкторы                                                             */
    set();                                                                      // Конструктор по умолчанию
    set(const set<T>& s);                                                       // Конструктор копирования
    set(set<T>&& s);                                                            // Конструктор переноса
    explicit set(std::initializer_list<T> lst);                                 // Конструктор со списком инициализации

    /* Полезное                                                                 */
    int get_length() const;                                                     // Получить размер множества
    bool contains(const T& elem) const;                                         // Проверить наличие элемента в множестве
    T* to_array() const;                                                        // Создание массива с содержанием множества

    /* Получение итераторов                                                     */
    Iterator<T> iterator_begin() const;                                         // Получить итератор, указывающий на начало множества
    Iterator<T> iterator_end() const;                                           // Получить итератор, указывающий на конец множества

    /* Getter'ы                                                                 */
    node<T>* get_first() const;                                                 // Получить указатель на первый элемент множества
    node<T>* get_last() const;                                                  // Получить указатель на последний элемент множества

    /* Манипуляции с размером                                                   */
    void add(const T& elem);                                                    // Добавить элемент
    void remove(const T& elem);                                                 // Удалить элемент
    void clear();                                                               // Очистить множество

    /* Операции множества                                                       */
    set<T>& set_union(const set<T>& s);                                          // Объединение множеств
    set<T>& set_intersection(const set<T>& s);                                   // Пересечение множеств
    set<T>& set_substract(const set<T>& s);                                      // Разность множеств

    /* Перегрузка операций                                                      */
    set<T>& operator= (const set<T>& lst);                                      // (перегрузка =)
    set<T>& operator+= (const set<T>& s);                                       // Объединение множеств (перегрузка +=)
    set<T>& operator*= (const set<T>& s);                                       // Пересечение множеств (перегрузка *=)
    set<T>& operator/= (const set<T>& s);                                       // Разность множеств (перегрузка /=)

    /* Функции друзья                                                           */
    template <typename _T>
    friend std::ostream& operator<< (std::ostream& os, const set<_T>& lst);     // Вывод класса в поток (перегрузка <<)
    template <typename _T>
    friend set<_T> operator+ (const set<_T>& s1, const set<_T>& s2);            // Объединение множеств (перегрузка +)
    template <typename _T>
    friend set<_T> operator* (const set<_T>& s1, const set<_T>& s2);            // Пересечение множеств (перегрузка *)
    template <typename _T>
    friend set<_T> operator/ (const set<_T>& s1, const set<_T>& s2);            // Разность множеств (перегрузка /)

    /* Деструктор                                                               */
    ~set();                                                                     // Деструктор

private:
    /* Свойства                                                                 */
    node<T>* first;                                                             // Указатель на первый элемент множества
    node<T>* last;                                                              // Указатель на последний элемент множества
};

#endif // SET_H
