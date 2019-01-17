#include "configurationdialog.h"
#include "ui_configurationdialog.h"

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationDialog)
{
    ui->setupUi(this);
}

ConfigurationDialog::~ConfigurationDialog()
{
    delete ui;
}

void ConfigurationDialog::setSettings(QSettings *settings)

{
   m_settings = settings;
   if (m_settings)
       ui->terminalEd->setText(m_settings->value("terminal").toString());
}

void ConfigurationDialog::on_buttonBox_accepted()
{
    m_settings->setValue("terminal", ui->terminalEd->text());
    m_settings->sync();
}
