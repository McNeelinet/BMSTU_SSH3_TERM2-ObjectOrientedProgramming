#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class set;

template <typename T>
class Iterator
{
public:
    /* Конструкторы                             */
    Iterator<T>(const set<T>& container_obj);   // Конструктор с использованием контейнерного класса

    /* Полезное                                 */
    T value();                                  // Получить значение текущего объекта
    bool is_end();                              // Проверка на конечный элемент

    /* Getter'ы                                 */
    node<T>* get_object();                      // Получение текущего объекта

    /* Перемещение                              */
    Iterator<T> next();                         // Перейти к следующему объекту

    /* Перегрузка операций                      */
    T& operator* ();                            // Исп. value() (перегрузка оператора разыменовывания)
    Iterator<T>& operator++ ();                 // Исп. next() (перегрузка префиксного инкремента)
    bool operator== (Iterator<T>& b);           // Сравнение итераторов (перегрузка оператора сравнения)
    bool operator!= (Iterator<T>& b);           // Сравнение итераторов (перегрузка оператора сравнения)

    /* Деструктор                               */
    ~Iterator();                                // Деструктор
private:
    /* Свойства                                 */
    node<T>* cur_node;
};

#endif // ITERATOR_H
