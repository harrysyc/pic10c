#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboard.h"
/*
 * Constructor
 * set the layout of the game
 *
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
gamename = new QLabel ("Welcome to Snake!");
difficulty = new QLabel ("Press to start!");
start = new QPushButton ("start");
levellayout = new QVBoxLayout;
levellayout->addWidget(difficulty);
levellayout->addWidget(start);
final_layout = new QVBoxLayout;
final_layout->addWidget(gamename);
final_layout->addLayout(levellayout);
central = new QWidget;
central->setLayout(final_layout);
this->setCentralWidget(central);


}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent *e)
{
e->ignore();
qwidget->show();
}

void MainWindow::setQuitWidget(QuitWidget* quit_widget)
{
    qwidget = quit_widget;
}
/*
 *
 * member function
 * set gameboard slots
 *
 */
void MainWindow::setGameBoard(GameBoard* game_board)
{
    board = game_board;

    QObject::connect(start, SIGNAL(clicked()), board, SLOT(show()));
}
