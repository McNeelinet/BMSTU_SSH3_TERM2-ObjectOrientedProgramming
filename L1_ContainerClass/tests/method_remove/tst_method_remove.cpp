#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_remove : public QObject
{
    Q_OBJECT

public:
    method_remove();
    ~method_remove();

private slots:
    void test_empty();
    void test_filled();
    void test_removed_value();
};

void method_remove::test_empty()
{
    set<int> my_set;

    QCOMPARE(my_set.get_length(), 0);

    QVERIFY_EXCEPTION_THROWN(my_set.remove(42), std::invalid_argument);
    QCOMPARE(my_set.get_length(), 0);
}

void method_remove::test_filled()
{
    set<int> my_set{1, 2, 3};

    QCOMPARE(my_set.get_length(), 3);
    QCOMPARE(my_set.contains(1), true);
    QCOMPARE(my_set.contains(2), true);
    QCOMPARE(my_set.contains(3), true);

    my_set.remove(2);

    QCOMPARE(my_set.get_length(), 2);
    QCOMPARE(my_set.contains(1), true);
    QCOMPARE(my_set.contains(3), true);
}

void method_remove::test_removed_value()
{
    set<int> my_set{1, 2, 3};

    my_set.remove(2);

    QVERIFY_EXCEPTION_THROWN(my_set.remove(2), std::invalid_argument);
    QCOMPARE(my_set.get_length(), 2);
    QCOMPARE(my_set.contains(1), true);
    QCOMPARE(my_set.contains(3), true);
}

method_remove::method_remove()
{

}

method_remove::~method_remove()
{

}

QTEST_APPLESS_MAIN(method_remove)

#include "tst_method_remove.moc"
