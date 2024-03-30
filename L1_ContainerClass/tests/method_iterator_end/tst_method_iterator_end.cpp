#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_iterator_end : public QObject
{
    Q_OBJECT

public:
    method_iterator_end();
    ~method_iterator_end();

private slots:
    void test_empty();
    void test_filled();
};

void method_iterator_end::test_empty()
{
    set<int> my_set;

    QCOMPARE(my_set.iterator_end().get_object(), nullptr);
}

void method_iterator_end::test_filled()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.iterator_end().get_object(), nullptr);
}

method_iterator_end::method_iterator_end()
{

}

method_iterator_end::~method_iterator_end()
{

}

QTEST_APPLESS_MAIN(method_iterator_end)

#include "tst_method_iterator_end.moc"
