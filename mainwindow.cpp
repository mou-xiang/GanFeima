#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../assets/gfms.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    w_mgr.init();
    w_mgr.load_music_from_array(__assets_gfms_mp3, __assets_gfms_mp3_len);
}

MainWindow::~MainWindow()
{
    w_mgr.free();
    delete ui;
}

void MainWindow::on_commitButton_clicked()
{
    w_finder.load_string(ui->textEdit->toPlainText().toStdString().c_str());

    if (w_finder.find_feima()) {
        w_mgr.play_music();
    }
}


void MainWindow::on_clearButton_clicked()
{
    w_finder.load_string("");
    ui->textEdit->clear();
}

