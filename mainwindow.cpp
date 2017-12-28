#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    num_modem = 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAbout_this_Application_triggered()
{
    QMessageBox::about(this,
        "About Virtual Modem",
        "(c) 2017 Jens Kallup\n"
        "non-profit Software");
}

void MainWindow::on_action_about_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionGo_triggered()
{
    ui->actionGo  ->setEnabled(false);
    ui->actionStop->setEnabled(true);
}

void MainWindow::on_actionStop_triggered()
{
    ui->actionGo  ->setEnabled(true);
    ui->actionStop->setEnabled(false);

    ui->actionModemListen->setChecked(false);
}

void MainWindow::on_actionAddModem_triggered()
{
    ++num_modem;
    if (num_modem > 4) {
        QMessageBox::critical(this,
        tr("Error"),
        tr("Limit of available Modem exceed's."));
        return;
    }
    QTreeWidgetItem * new_item = new
    QTreeWidgetItem(ui->treeWidget);
    new_item->setText(0,
        QString("Modem %1").
        arg(num_modem));
}
