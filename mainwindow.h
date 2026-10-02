#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fm_finder.h>
#include <audiomgr.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_commitButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;

    Fm_Finder w_finder;
    A_Mgr w_mgr;
};
#endif // MAINWINDOW_H
