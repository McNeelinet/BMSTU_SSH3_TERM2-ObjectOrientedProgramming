#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_copy_constructor : public QObject
{
    Q_OBJECT

public:
    method_copy_constructor();
    ~method_copy_constructor();

private slots:
    void test_empty_empty();
    void test_empty_filled();
    void test_filled_empty();
    void test_filled_filled();
};

void method_copy_constructor::test_empty_empty()
{
    set<int> my_set1;
    set<int> my_set2(my_set1);

    QCOMPARE(my_set1.get_length(), 0);
    QCOMPARE(my_set2.get_length(), 0);
}

void method_copy_constructor::test_empty_filled()
{
    set<int> my_set1;
    set<int> my_set2{1, 2, 3};

    my_set2 = my_set1;

    QCOMPARE(my_set1.get_length(), 0);
    QCOMPARE(my_set2.get_length(), 0);
}

void method_copy_constructor::test_filled_empty()
{
    set<int> my_set1{1, 2, 3};
    set<int> my_set2(my_set1);

    QCOMPARE(my_set1.get_length(), 3);
    QCOMPARE(my_set1.contains(1), true);
    QCOMPARE(my_set1.contains(2), true);
    QCOMPARE(my_set1.contains(3), true);

    QCOMPARE(my_set2.get_length(), 3);
    QCOMPARE(my_set2.contains(1), true);
    QCOMPARE(my_set2.contains(2), true);
    QCOMPARE(my_set2.contains(3), true);
}

void method_copy_constructor::test_filled_filled()
{
    set<int> my_set1{1, 2, 3};
    set<int> my_set2{4, 5, 6};

    my_set2 = my_set1;

    QCOMPARE(my_set1.get_length(), 3);
    QCOMPARE(my_set1.contains(1), true);
    QCOMPARE(my_set1.contains(2), true);
    QCOMPARE(my_set1.contains(3), true);

    QCOMPARE(my_set2.get_length(), 3);
    QCOMPARE(my_set2.contains(1), true);
    QCOMPARE(my_set2.contains(2), true);
    QCOMPARE(my_set2.contains(3), true);
}

method_copy_constructor::method_copy_constructor()
{

}

method_copy_constructor::~method_copy_constructor()
{

}

QTEST_APPLESS_MAIN(method_copy_constructor)

#include "tst_method_copy_constructor.moc"
