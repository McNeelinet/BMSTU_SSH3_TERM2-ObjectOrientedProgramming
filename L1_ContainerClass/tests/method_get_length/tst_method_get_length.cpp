#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_get_length : public QObject
{
    Q_OBJECT

public:
    method_get_length();
    ~method_get_length();

private slots:
    void test_empty_stable();
    void test_filled_stable();
    void test_empty_growing();
    void test_filled_growing();
    void test_filled_falling();
    void test_empty_random();
    void test_filled_random();
};

method_get_length::method_get_length()
{

}

method_get_length::~method_get_length()
{

}

void method_get_length::test_empty_stable()
{
    set<int> my_set;

    QCOMPARE(my_set.get_length(), 0);
    QCOMPARE(my_set.get_length(), 0);
}

void method_get_length::test_filled_stable()
{
    set<int> my_set1{1, 2, 3};

    QCOMPARE(my_set1.get_length(), 3);
    QCOMPARE(my_set1.get_length(), 3);

    set<int> my_set2{1, 2, 3, 4, 5};

    QCOMPARE(my_set2.get_length(), 5);
    QCOMPARE(my_set2.get_length(), 5);
}

void method_get_length::test_empty_growing()
{
    set<int> my_set;

    QCOMPARE(my_set.get_length(), 0);

    my_set.add(1);

    QCOMPARE(my_set.get_length(), 1);

    my_set.add(2);
    my_set.add(3);

    QCOMPARE(my_set.get_length(), 3);
}

void method_get_length::test_filled_growing()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.get_length(), 3);

    my_set.add(4);

    QCOMPARE(my_set.get_length(), 4);

    my_set.add(5);
    my_set.add(6);

    QCOMPARE(my_set.get_length(), 6);
}

void method_get_length::test_filled_falling()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.get_length(), 3);

    my_set.remove(3);

    QCOMPARE(my_set.get_length(), 2);

    my_set.remove(2);
    my_set.remove(1);

    QCOMPARE(my_set.get_length(), 0);
}

void method_get_length::test_empty_random()
{
    set<int> my_set;

    QCOMPARE(my_set.get_length(), 0);

    my_set.add(1);
    my_set.add(2);

    QCOMPARE(my_set.get_length(), 2);

    my_set.remove(2);

    QCOMPARE(my_set.get_length(), 1);

    my_set.add(3);

    QCOMPARE(my_set.get_length(), 2);

    my_set.remove(3);
    my_set.remove(1);

    QCOMPARE(my_set.get_length(), 0);
}

void method_get_length::test_filled_random()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.get_length(), 3);

    my_set.remove(3);
    my_set.remove(2);

    QCOMPARE(my_set.get_length(), 1);

    my_set.add(2);

    QCOMPARE(my_set.get_length(), 2);

    my_set.remove(2);

    QCOMPARE(my_set.get_length(), 1);

    my_set.add(2);
    my_set.add(3);

    QCOMPARE(my_set.get_length(), 3);
}

QTEST_APPLESS_MAIN(method_get_length)

#include "tst_method_get_length.moc"
