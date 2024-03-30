#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_iterator_begin : public QObject
{
    Q_OBJECT

public:
    method_iterator_begin();
    ~method_iterator_begin();

private slots:
    void test_empty();
    void test_filled();
};

void method_iterator_begin::test_empty()
{
    set<int> my_set;

    QCOMPARE(my_set.iterator_begin().get_object(), my_set.get_first());
}

void method_iterator_begin::test_filled()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.iterator_begin().get_object(), my_set.get_first());
}

method_iterator_begin::method_iterator_begin()
{

}

method_iterator_begin::~method_iterator_begin()
{

}

QTEST_APPLESS_MAIN(method_iterator_begin)

#include "tst_method_iterator_begin.moc"
