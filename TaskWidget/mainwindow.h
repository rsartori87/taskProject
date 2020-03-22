#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QSystemTrayIcon>

class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class Period;
class FileTask;
class StringTask;

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent* event) override;
private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
private:
    void createTrayIcon();
    void createTextGroup();
    void createFileGroup();

    void chooseFile();
private:
    QGroupBox* textGroup;
    QLabel* textLabel;
    QLineEdit* textLineEdit;
    QPushButton* confirmTextButton;
    Period* textPeriod;
    StringTask* textTask = nullptr;

    QGroupBox* fileGroup;
    QLabel* fileLabel;
    QLineEdit* fileLineEdit;
    QPushButton* fileButton;
    QPushButton* confirmFileButton;
    Period* filePeriod;
    FileTask* fileTask = nullptr;

    QMenu* trayMenu;
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
