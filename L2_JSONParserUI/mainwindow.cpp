#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_open_file, SIGNAL(clicked()), this, SLOT(openFileDialog()));
    connect(ui->btn_analyse, SIGNAL(clicked()), this, SLOT(analyzeFile()));
}

void MainWindow::openFileDialog()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath(), "JSON файл (*.json)");

    if (!filename.isEmpty()) {
        this->ui->le_filename->setText(filename);
    }
}

void MainWindow::analyzeFile()
{
    JSON json(this->ui->le_filename->text().toStdString());

//    ParseResult result = json.parse();
//    this->ui->te_json_errors->setPlainText(QString::fromStdString(result.getPrettyErrorText()));
    this->ui->te_json_contents->setPlainText(QString::fromStdString(json.read()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

