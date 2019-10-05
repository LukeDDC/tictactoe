#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamebutton.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int row = 0; row< 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            GameButton *button = new GameButton(row, column, ui->gridLayoutWidget);
            button->setText("");
            ui->gridLayout->addWidget(button, row, column);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

