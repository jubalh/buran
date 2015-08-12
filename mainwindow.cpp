#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configurationdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QProcess>
#include <QFileInfo>
//#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    bool configFileExists;
    ui->setupUi(this);

    //TODO xdg/appname and under osx and windows seperate folder
    settingsFilename = QApplication::applicationDirPath() + "/settings.ini";
    qDebug() << "Config path" + QApplication::applicationDirPath() + "/settings.ini";

    QFileInfo fileinfo(settingsFilename);
    if(!(fileinfo.exists() && fileinfo.isFile()))
    {
        configFileExists = false;
        QFile file(settingsFilename);
        if (!file.open(QIODevice::WriteOnly))
            qDebug() << "Could not create config file " << settingsFilename;
        file.close();
    }

    m_settings = new QSettings(settingsFilename, QSettings::IniFormat);

    if (!configFileExists)
    {
        m_settings->setValue("terminal", "xterm -e");
        m_settings->sync();
    }

    this->readSshConfig();
    this->buildMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showConfig()
{
    ConfigurationDialog configDlg;
    configDlg.setSettings(m_settings);
    configDlg.exec();
}

void MainWindow::readSshConfig()
{
    //QFile sshConfigFile(QStandardPaths::HomeLocation + ".ssh/ssh_config");
    //TODO
    QFile sshConfigFile("/home/michael/.ssh/config");
    if(!sshConfigFile.open(QIODevice::ReadOnly| QIODevice::Text)) {
        QMessageBox::information(0, "error", sshConfigFile.errorString());
    }
    QTextStream in(&sshConfigFile);
    while (!in.atEnd())
    {
        QString line = in.readLine();

        QRegExp rx("^(#?)[ \\t]*([^ \\t=]+)[ \\t=]+(.*)$");
        rx.indexIn(line);

        //TODO test?
        QString tmp = rx.cap(0);
        if (tmp != "" && tmp.trimmed().at(0) == '#')
           continue;

        QString first = rx.cap(2).trimmed();
        QString second = rx.cap(3).trimmed();

        //TODO: ignore some.. *, ignorelist
        if(QString::compare(first, "Host", Qt::CaseSensitive) == 0)
            servers.append(second);
    }
}

void MainWindow::buildMenu()
{
    QAction *quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QAction *openConfigureAction = new QAction(tr("&Configure"), this);
    connect(openConfigureAction, SIGNAL(triggered()), this, SLOT(showConfig()));

    trayIcon = new QSystemTrayIcon(this);
    trayIconMenu = new QMenu(this);

    for (QVector<QString>::iterator i = servers.begin(); i != servers.end(); i++)
    {
        QAction *connectAction = new QAction((*i), this);
        connectAction->setProperty("name", *i);
        trayIconMenu->addAction(connectAction);
        connect(connectAction, SIGNAL(triggered()), this, SLOT(startSsh()));
    }

    trayIconMenu->addSeparator();
    trayIconMenu->addAction(openConfigureAction);
    trayIconMenu->addAction(quitAction);

    trayIcon->setIcon(QIcon(":/images/logo.png"));
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setVisible(true);
}

void MainWindow::startSsh()
{
    if (sender() != NULL )
    {
        QString name = sender()->property("name").toString();
        QProcess *termProcess = new QProcess(this);
        QString sshcall =  m_settings->value("terminal").toString() + " \"ssh " + name + "\"";
        termProcess->start(sshcall);
        qDebug() << ("calling: " + sshcall);
    }
}
