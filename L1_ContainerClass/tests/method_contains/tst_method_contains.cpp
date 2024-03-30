#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_contains : public QObject
{
    Q_OBJECT

public:
    method_contains();
    ~method_contains();

private slots:
    void test_contains_empty();
    void test_contains_filled_exist();
    void test_contains_filled_not_exist();
    void test_contains_filled_exist_then_not_exist();
    void test_contains_filled_not_exist_then_exist();
};

void method_contains::test_contains_empty()
{
    set<int> my_set;

    QCOMPARE(my_set.contains(54), false);
}

void method_contains::test_contains_filled_exist()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.contains(2), true);
}

void method_contains::test_contains_filled_not_exist()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.contains(5), false);
}

void method_contains::test_contains_filled_exist_then_not_exist()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.contains(2), true);

    my_set.remove(2);

    QCOMPARE(my_set.contains(2), false);
}

void method_contains::test_contains_filled_not_exist_then_exist()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.contains(5), false);

    my_set.add(5);

    QCOMPARE(my_set.contains(2), true);
}

method_contains::method_contains()
{

}

method_contains::~method_contains()
{

}

QTEST_APPLESS_MAIN(method_contains)

#include "tst_method_contains.moc"
