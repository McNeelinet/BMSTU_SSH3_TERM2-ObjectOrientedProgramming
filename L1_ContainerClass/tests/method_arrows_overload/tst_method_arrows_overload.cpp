#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_arrows_overload : public QObject
{
    Q_OBJECT

public:
    method_arrows_overload();
    ~method_arrows_overload();

private slots:
    void test_empty();
    void test_filled();
};

void method_arrows_overload::test_empty()
{
    set<int> my_set1{};

    std::cout << my_set1 << "\n";
}

void method_arrows_overload::test_filled()
{
    set<int> my_set1{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::cout << my_set1 << "\n";
}

method_arrows_overload::method_arrows_overload()
{

}

method_arrows_overload::~method_arrows_overload()
{

}

QTEST_APPLESS_MAIN(method_arrows_overload)

#include "tst_method_arrows_overload.moc"
