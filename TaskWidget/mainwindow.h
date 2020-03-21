#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class MainWindow : public QMainWindow
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
private:
    QSystemTrayIcon *trayIcon;
    QMenu* trayMenu;
};
#endif // MAINWINDOW_H
