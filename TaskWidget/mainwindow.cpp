#include "mainwindow.h"
#include <QMenu>
#include <QStyle>
#include <QApplication>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createTrayIcon();
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (this->isVisible()) {
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        trayIcon->showMessage("Task Program",
                              "Il programma rimmarrà in esecuzione in background, per chiudere il programma fare click su esci, nel menu.",
                              icon,
                              2000);
    }
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        if (this->isVisible()) {
            this->hide();
        } else {
            this->show();
        }
        break;
    default:
        break;
    }
}

void MainWindow::createTrayIcon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("Tray program");
    trayMenu = new QMenu(this);
    QAction* viewWindow = new QAction("Apri", this);
    QAction* quitAction = new QAction("Esci", this);

    connect(viewWindow, &QAction::triggered, this, &MainWindow::show);
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

    trayMenu->addAction(viewWindow);
    trayMenu->addAction(quitAction);

    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
}

