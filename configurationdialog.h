#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class ConfigurationDialog;
}

class ConfigurationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigurationDialog(QWidget *parent = 0);
    ~ConfigurationDialog();
    void setSettings(QSettings *settings);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConfigurationDialog *ui;
    QSettings *m_settings;
};

#endif // CONFIGURATIONDIALOG_H
