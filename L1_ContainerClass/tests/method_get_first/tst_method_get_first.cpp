#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_get_first : public QObject
{
    Q_OBJECT

public:
    method_get_first();
    ~method_get_first();

private slots:
    void test_empty();
    void test_filled();
    void test_empty_add_filled();
    void test_empty_copy_filled();
    void test_filled_remove_empty();
    void test_filled_clear_empty();
    void test_filled_copy_empty();
};

void method_get_first::test_empty()
{
    set<int> my_set;

    QCOMPARE(my_set.get_first(), nullptr);
}

void method_get_first::test_filled()
{
    set<int> my_set{1, 2, 3, 4, 5};

    QCOMPARE(my_set.get_first()->content, 1);
}

void method_get_first::test_empty_add_filled()
{
    set<int> my_set;

    QCOMPARE(my_set.get_first(), nullptr);

    my_set.add(10);

    QCOMPARE(my_set.get_first()->content, 10);
}

void method_get_first::test_empty_copy_filled()
{
    set<int> my_set1;
    set<int> my_set2{10, 20, 30};

    QCOMPARE(my_set1.get_first(), nullptr);

    my_set1 = my_set2;

    QCOMPARE(my_set1.get_first()->content, 10);
}

void method_get_first::test_filled_remove_empty()
{
    set<int> my_set{10};

    QCOMPARE(my_set.get_first()->content, 10);

    my_set.remove(10);

    QCOMPARE(my_set.get_first(), nullptr);
}

void method_get_first::test_filled_clear_empty()
{
    set<int> my_set{10, 20, 30};

    QCOMPARE(my_set.get_first()->content, 10);

    my_set.clear();

    QCOMPARE(my_set.get_first(), nullptr);
}

void method_get_first::test_filled_copy_empty()
{
    set<int> my_set1{10, 20, 30};
    set<int> my_set2;

    QCOMPARE(my_set1.get_first()->content, 10);

    my_set1 = my_set2;

    QCOMPARE(my_set1.get_first(), nullptr);
}

method_get_first::method_get_first()
{

}

method_get_first::~method_get_first()
{

}

QTEST_APPLESS_MAIN(method_get_first)

#include "tst_method_get_first.moc"
