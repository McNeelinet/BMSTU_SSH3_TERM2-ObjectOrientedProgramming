#include "mainwindow.h"
#include <QApplication>
#include "JSONParser/JSONParser.h"
#include <iostream>


/* Тестирование синтаксического анализатора */
//int main()
//{
//    JSON json("/home/mcneelinet/Рабочий стол/test.json");
//    ParseResult result = json.parse();
//    std::cout << result.getPrettyErrorText();
//}

/* Тестирование вывода текста */
//int main()
//{
//    JSON json("/home/mcneelinet/Рабочий стол/test.json");
//    std::cout << json.read();
//}


/* Тестирование интерфейса */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
