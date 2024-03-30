#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_slash : public QObject
{
    Q_OBJECT

public:
    method_slash();
    ~method_slash();

private slots:
    void test_empty_empty();
    void test_empty_filled();
    void test_filled_empty();
    void test_filled_filled();
    void test_all_double_values();
    void test_some_double_values();
};

void method_slash::test_empty_empty()
{
    set<int> my_set1;
    set<int> my_set2;

    set<int> s_union = my_set1 / my_set2;

    QCOMPARE(s_union.get_length(), 0);
}

void method_slash::test_empty_filled()
{
    set<int> my_set1;
    set<int> my_set2{1, 2, 3, 4, 5};

    set<int> s_union = my_set1 / my_set2;

    QCOMPARE(s_union.get_length(), 5);
    QCOMPARE(s_union.contains(1), true);
    QCOMPARE(s_union.contains(2), true);
    QCOMPARE(s_union.contains(3), true);
    QCOMPARE(s_union.contains(4), true);
    QCOMPARE(s_union.contains(5), true);
}

void method_slash::test_filled_empty()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2;

    set<int> s_union = my_set1 / my_set2;

    QCOMPARE(s_union.get_length(), 5);
    QCOMPARE(s_union.contains(1), true);
    QCOMPARE(s_union.contains(2), true);
    QCOMPARE(s_union.contains(3), true);
    QCOMPARE(s_union.contains(4), true);
    QCOMPARE(s_union.contains(5), true);
}

void method_slash::test_filled_filled()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{6, 7, 8, 9, 0};

    set<int> s_union = my_set1 / my_set2;

    QCOMPARE(s_union.get_length(), 10);
    QCOMPARE(s_union.contains(1), true);
    QCOMPARE(s_union.contains(2), true);
    QCOMPARE(s_union.contains(3), true);
    QCOMPARE(s_union.contains(4), true);
    QCOMPARE(s_union.contains(5), true);
    QCOMPARE(s_union.contains(6), true);
    QCOMPARE(s_union.contains(7), true);
    QCOMPARE(s_union.contains(8), true);
    QCOMPARE(s_union.contains(9), true);
    QCOMPARE(s_union.contains(0), true);
}

void method_slash::test_all_double_values()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{1, 2, 3, 4, 5};

    set<int> s_union = my_set1 / my_set2;

    QCOMPARE(s_union.get_length(), 0);
}

void method_slash::test_some_double_values()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{1, 3, 5, 6, 7, 8, 9, 0};

    set<int> s_union = my_set1 / my_set2;

    QCOMPARE(s_union.get_length(), 7);
    QCOMPARE(s_union.contains(2), true);
    QCOMPARE(s_union.contains(4), true);
    QCOMPARE(s_union.contains(6), true);
    QCOMPARE(s_union.contains(7), true);
    QCOMPARE(s_union.contains(8), true);
    QCOMPARE(s_union.contains(9), true);
    QCOMPARE(s_union.contains(0), true);
}

method_slash::method_slash()
{

}

method_slash::~method_slash()
{

}

QTEST_APPLESS_MAIN(method_slash)

#include "tst_method_slash.moc"
