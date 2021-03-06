#include "mainwindow.h"
#include <QMenu>
#include <QStyle>
#include <QApplication>
#include <QCloseEvent>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>

#include "period.h"
#include "trigger.h"
#include "filetask.h"
#include "stringtask.h"
#include <vector>
#include <utility>

constexpr int MESSAGE_DURATION = 2000;

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    createTextGroup();
    createFileGroup();
    createTrayIcon();

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(textGroup);
    mainLayout->addWidget(fileGroup);
    setLayout(mainLayout);

    textPeriod = new Period(this);
    std::vector<int> textSeconds{0, 10, 20, 30, 40, 50 };
    Trigger textTrigger(Trigger::SECOND, std::move(textSeconds));
    textPeriod->addTrigger(textTrigger);

    filePeriod = new Period(this);
    std::vector<int> fileSeconds{ 0, 30 };
    Trigger fileTrigger(Trigger::SECOND, std::move(fileSeconds));
    filePeriod->addTrigger(fileTrigger);

    resize(400, 300);
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
                              MESSAGE_DURATION);
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

void MainWindow::createTextGroup()
{
    textGroup = new QGroupBox("Impostazioni testo");
    textLabel = new QLabel("Testo");
    confirmTextButton = new QPushButton("Conferma");

    textLineEdit = new QLineEdit;
    QGridLayout* textLayout = new QGridLayout;
    textLayout->addWidget(textLabel, 0, 0);
    textLayout->addWidget(textLineEdit, 0, 1);
    textLayout->addWidget(confirmTextButton, 1, 0);
    textGroup->setLayout(textLayout);

    connect(confirmTextButton, &QPushButton::clicked, [=]() {
        delete textTask;
        textTask = nullptr;
        if (!textLineEdit->text().isEmpty())
            textTask = new StringTask(textLineEdit->text(), textPeriod, this);
        showSuccess();
    });
}

void MainWindow::createFileGroup()
{
    fileGroup = new QGroupBox("Impostazioni file");
    fileLabel = new QLabel("File");
    fileLineEdit = new QLineEdit;
    fileButton = new QPushButton("Sfoglia");
    confirmFileButton = new QPushButton("Conferma");

    connect(fileButton, &QPushButton::clicked, [=]() {
        chooseFile();
    });

    connect(confirmFileButton, &QPushButton::clicked, [=]() {
        delete fileTask;
        fileTask = nullptr;
        if (!fileLineEdit->text().isEmpty())
            fileTask = new FileTask(fileLineEdit->text(), filePeriod, this);
        showSuccess();
    });

    QGridLayout* fileLayout = new QGridLayout;
    fileLayout->addWidget(fileLabel, 0, 0);
    fileLayout->addWidget(fileLineEdit, 0, 1);
    fileLayout->addWidget(fileButton, 0, 2);
    fileLayout->addWidget(confirmFileButton, 1, 0);
    fileGroup->setLayout(fileLayout);
}

void MainWindow::chooseFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Scegli file",
                                                    QStandardPaths::standardLocations(QStandardPaths::HomeLocation).first());
    fileLineEdit->setText(filename);
}

void MainWindow::showSuccess()
{
    QMessageBox::information(this,
                             "Task Application",
                             "Modifiche applicate con successo",
                             QMessageBox::Ok);
}

