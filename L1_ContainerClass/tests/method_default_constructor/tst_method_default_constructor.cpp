#include <QtTest>

#include "../../set/Iterator.h"
#include "../../set/set.h"
#include "../../set/Iterator.cpp"
#include "../../set/set.cpp"

class method_default_constructor : public QObject
{
    Q_OBJECT

public:
    method_default_constructor();
    ~method_default_constructor();

private slots:
    void test_default();

};

void method_default_constructor::test_default()
{
    set<int> my_set;

    QCOMPARE(my_set.get_length(), 0);
}

method_default_constructor::method_default_constructor()
{

}

method_default_constructor::~method_default_constructor()
{

}

QTEST_APPLESS_MAIN(method_default_constructor)

#include "tst_method_default_constructor.moc"
