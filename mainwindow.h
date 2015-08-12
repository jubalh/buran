#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QVector>
#include <QString>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showConfig();
    void startSsh();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    QVector<QString> servers;
    QMenu *trayIconMenu;
    QString settingsFilename;
    QSettings *m_settings;
    void readSshConfig();
    void buildMenu();
};

#endif // MAINWINDOW_H
