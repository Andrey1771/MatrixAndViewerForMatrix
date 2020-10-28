#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class Matrix;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::shared_ptr<Matrix> matrix{nullptr};

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
