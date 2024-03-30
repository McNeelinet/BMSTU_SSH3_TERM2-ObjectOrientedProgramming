#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_clear : public QObject
{
    Q_OBJECT

public:
    method_clear();
    ~method_clear();

private slots:
    void test_empty();
    void test_filled();
};

void method_clear::test_empty()
{
    set<int> my_set;

    QCOMPARE(my_set.get_length(), 0);

    my_set.clear();

    QCOMPARE(my_set.get_length(), 0);
}

void method_clear::test_filled()
{
    set<int> my_set{1, 2, 3, 4, 5};

    QCOMPARE(my_set.get_length(), 5);

    my_set.clear();

    QCOMPARE(my_set.get_length(), 0);
}

method_clear::method_clear()
{

}

method_clear::~method_clear()
{

}

QTEST_APPLESS_MAIN(method_clear)

#include "tst_method_clear.moc"
