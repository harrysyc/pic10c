#include "mainwindow.h"
#include "quitwidget.h"
#include "gameboard.h"
#include "QWidget"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QGridLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuitWidget* qwidget = new QuitWidget;
    MainWindow* w = new MainWindow;
    GameBoard* b = new GameBoard;
    w->setQuitWidget(qwidget);
    w->setWindowTitle("Enjoy the Game!");
// set the quitwidget
   b->setQuitWidget(qwidget);
    w->setGameBoard(b);
    b->setMainWindow(w);
    w->show();
    QObject::connect(qwidget->quit_ok, SIGNAL(clicked()), &a, SLOT(quit()));

    return a.exec();
}
