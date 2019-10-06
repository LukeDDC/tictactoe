#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamebutton.h"
#include "QObject"
#include "tictactoe.h"
#include "QDebug"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TicTacToe *game;
    QList<GameButton *> *gameButtons;

public slots:
    void handleGameButtonClick();
    void handleResetButtonClick();
};
#endif // MAINWINDOW_H
