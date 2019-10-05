#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QWidget>
#include <QPushButton>

class GameButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GameButton(QWidget *parent = nullptr);
    GameButton(int, int, QWidget *parent = nullptr);
    ~GameButton();
    void setX(int);
    void setY(int);
    int getX(int);
    int getY(int);

private:
    int x;
    int y;

signals:

public slots:
};

#endif // GAMEBUTTON_H
