#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QSystemTrayIcon>

class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;

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
private:
    QGroupBox* textGroup;
    QLabel* textLabel;
    QLineEdit* textLineEdit;

    QGroupBox* fileGroup;
    QLabel* fileLabel;
    QLineEdit* fileLineEdit;

    QMenu* trayMenu;
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
