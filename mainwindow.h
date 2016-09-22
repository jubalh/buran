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
    QSystemTrayIcon *m_trayIcon;
    QVector<QString> m_servers;
    QMenu *trayIconMenu;
    QSettings *m_settings;
    void readSshConfig();
    void buildMenu();
    void findOrAddMenuItem(QMenu *menu, const QList<QString> &titles, const QString &hostname);
};

#endif // MAINWINDOW_H
