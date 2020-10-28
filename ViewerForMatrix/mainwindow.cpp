#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrixmodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    matrix = std::shared_ptr<Matrix>(new Matrix);
    std::vector<int> vect = {1, 2, 3, 4, 5, 6, 7, 8, 98, 453, 342, 12};
    matrix.get()->addRow(vect);
    matrix.get()->addRow(vect);
    matrix.get()->addRow(vect);
    MatrixModel* model = new MatrixModel(*matrix.get(), this);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}
