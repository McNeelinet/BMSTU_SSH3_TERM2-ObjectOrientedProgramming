#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_star_equal_overload : public QObject
{
    Q_OBJECT

public:
    method_star_equal_overload();
    ~method_star_equal_overload();

private slots:
    void test_empty_empty();
    void test_empty_filled();
    void test_filled_empty();
    void test_filled_filled();
    void test_all_double_values();
    void test_some_double_values();
};

void method_star_equal_overload::test_empty_empty()
{
    set<int> my_set1;
    set<int> my_set2;

    my_set1 *= my_set2;

    QCOMPARE(my_set1.get_length(), 0);
}

void method_star_equal_overload::test_empty_filled()
{
    set<int> my_set1;
    set<int> my_set2{1, 2, 3, 4, 5};

    my_set1 *= my_set2;

    QCOMPARE(my_set1.get_length(), 0);
}

void method_star_equal_overload::test_filled_empty()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2;

    my_set1 *= my_set2;

    QCOMPARE(my_set1.get_length(), 0);
}

void method_star_equal_overload::test_filled_filled()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{6, 7, 8, 9, 0};

    my_set1 *= my_set2;

    QCOMPARE(my_set1.get_length(), 0);
}

void method_star_equal_overload::test_all_double_values()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{1, 2, 3, 4, 5};

    my_set1 *= my_set2;

    QCOMPARE(my_set1.get_length(), 5);
    QCOMPARE(my_set1.contains(1), true);
    QCOMPARE(my_set1.contains(2), true);
    QCOMPARE(my_set1.contains(3), true);
    QCOMPARE(my_set1.contains(4), true);
    QCOMPARE(my_set1.contains(5), true);
}

void method_star_equal_overload::test_some_double_values()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{1, 3, 5, 6, 7, 8, 9, 0};

    my_set1 *= my_set2;

    QCOMPARE(my_set1.get_length(), 3);
    QCOMPARE(my_set1.contains(1), true);
    QCOMPARE(my_set1.contains(3), true);
    QCOMPARE(my_set1.contains(5), true);
}

method_star_equal_overload::method_star_equal_overload()
{

}

method_star_equal_overload::~method_star_equal_overload()
{

}

QTEST_APPLESS_MAIN(method_star_equal_overload)

#include "tst_method_star_equal_overload.moc"
