#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrixmodel.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    matrix = std::shared_ptr<Matrix>(new Matrix);
    std::vector<int> vect = {2, 2, 3, 4, 5, 6, 7, 8, 98, 453, 342, 12};
    std::vector<int> vect2 = {1, 2, 4, 8, 5, 6, 99, 8};
    std::vector<int> vect3 = {43, 2, 3, 54, 5, 6, 34, 8, 98, 53, 342, 12};
    std::vector<std::vector<int>> vect4 = { {1, 4, 4, 3},
                                            {},
                                            {43, 2, 3, 54, 5, 6, 34, 8, 98, 53, 342, 12}
                                          };
    matrix.get()->addRow(vect);
    matrix.get()->addRow(vect2);
    matrix.get()->addRow(vect3);

    matrix->removeRow(0);
    matrix->removeRow(1);
    qDebug() << "size: " << matrix->columnCount();
    matrix->removeColumn(11);
    matrix->removeColumn(0);
    matrix->removeColumn(0);
    matrix->assignRows(vect4);

    Matrix matr(-11, 2, 2);
    matrix->setMatrix(matr, 0, 2);
    MatrixModel* model = new MatrixModel(*matrix.get(), this);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);

}

MainWindow::~MainWindow()
{
    delete ui;
}
