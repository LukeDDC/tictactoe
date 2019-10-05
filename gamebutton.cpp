#include "gamebutton.h"

GameButton::GameButton(QWidget *parent) : QPushButton(parent)
{
}

GameButton::GameButton(int x, int y, QWidget *parent) : QPushButton(parent)
{
    this->setX(x);
    this->setY(y);
}

GameButton::~GameButton()
{
}

void GameButton::setX(int x)
{
    this->x = x;
}
void GameButton::setY(int y)
{
    this->y = y;
}
int GameButton::getX(int)
{
  return this->x;
}
int GameButton::getY(int)
{
  return this->y;
}
