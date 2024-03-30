#include <QtTest>
#include <stdexcept>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_add : public QObject
{
    Q_OBJECT

public:
    method_add();
    ~method_add();

private slots:
    void test_empty();
    void test_filled();
    void test_doubled_values();
};

void method_add::test_empty()
{
    set<int> my_set;

    QCOMPARE(my_set.get_length(), 0);

    my_set.add(1);

    QCOMPARE(my_set.get_length(), 1);
    QCOMPARE(my_set.contains(1), true);
}

void method_add::test_filled()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.get_length(), 3);
    QCOMPARE(my_set.contains(1), true);
    QCOMPARE(my_set.contains(2), true);
    QCOMPARE(my_set.contains(3), true);

    my_set.add(4);

    QCOMPARE(my_set.get_length(), 4);
    QCOMPARE(my_set.contains(1), true);
    QCOMPARE(my_set.contains(2), true);
    QCOMPARE(my_set.contains(3), true);
    QCOMPARE(my_set.contains(4), true);
}

void method_add::test_doubled_values()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.get_length(), 3);
    QCOMPARE(my_set.contains(1), true);
    QCOMPARE(my_set.contains(2), true);
    QCOMPARE(my_set.contains(3), true);

    QVERIFY_EXCEPTION_THROWN(my_set.add(2), std::invalid_argument);
    QCOMPARE(my_set.get_length(), 3);
    QCOMPARE(my_set.contains(1), true);
    QCOMPARE(my_set.contains(2), true);
    QCOMPARE(my_set.contains(3), true);
}

method_add::method_add()
{

}

method_add::~method_add()
{

}

QTEST_APPLESS_MAIN(method_add)

#include "tst_method_add.moc"
