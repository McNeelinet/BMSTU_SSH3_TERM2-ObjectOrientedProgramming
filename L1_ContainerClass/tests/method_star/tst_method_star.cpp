#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_star : public QObject
{
    Q_OBJECT

public:
    method_star();
    ~method_star();

private slots:
    void test_empty_empty();
    void test_empty_filled();
    void test_filled_empty();
    void test_filled_filled();
    void test_all_double_values();
    void test_some_double_values();
};

void method_star::test_empty_empty()
{
    set<int> my_set1;
    set<int> my_set2;

    set<int> s_union = my_set1 * my_set2;

    QCOMPARE(s_union.get_length(), 0);
}

void method_star::test_empty_filled()
{
    set<int> my_set1;
    set<int> my_set2{1, 2, 3, 4, 5};

    set<int> s_union = my_set1 * my_set2;

    QCOMPARE(s_union.get_length(), 0);
}

void method_star::test_filled_empty()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2;

    set<int> s_union = my_set1 * my_set2;

    QCOMPARE(s_union.get_length(), 0);
}

void method_star::test_filled_filled()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{6, 7, 8, 9, 0};

    set<int> s_union = my_set1 * my_set2;

    QCOMPARE(s_union.get_length(), 0);
}

void method_star::test_all_double_values()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{1, 2, 3, 4, 5};

    set<int> s_union = my_set1 * my_set2;

    QCOMPARE(s_union.get_length(), 5);
    QCOMPARE(s_union.contains(1), true);
    QCOMPARE(s_union.contains(2), true);
    QCOMPARE(s_union.contains(3), true);
    QCOMPARE(s_union.contains(4), true);
    QCOMPARE(s_union.contains(5), true);
}

void method_star::test_some_double_values()
{
    set<int> my_set1{1, 2, 3, 4, 5};
    set<int> my_set2{1, 3, 5, 6, 7, 8, 9, 0};

    set<int> s_union = my_set1 * my_set2;

    QCOMPARE(s_union.get_length(), 3);
    QCOMPARE(s_union.contains(1), true);
    QCOMPARE(s_union.contains(3), true);
    QCOMPARE(s_union.contains(5), true);
}

method_star::method_star()
{

}

method_star::~method_star()
{

}

QTEST_APPLESS_MAIN(method_star)

#include "tst_method_star.moc"
