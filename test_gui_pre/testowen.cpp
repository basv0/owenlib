#include "testowen.h"
#include "ui_testowen.h"
#include <stdio.h>
#include </usr/local/include/owen/owen_io.h>

TestOwen::TestOwen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestOwen)
{
    //QTextCodec *codec = QTextCodec::codecForName("Utf8");
    //QTextCodec::setCodecForTr(codec);
    ui->setupUi(this);
    fd=-1;
}

TestOwen::~TestOwen()
{
    delete ui;
}

void TestOwen::on_rdbSerial_clicked(bool checked)
{
    if(checked){
        int n = ui->spbNum->value();
        QString num;
        QString sx = "/dev/ttyS"+num.setNum(n);
        ui->lblPort->setText(sx);
    }
}

void TestOwen::on_rdbUSB_clicked(bool checked)
{
    if(checked){
        int n = ui->spbNum->value();
        QString num;
        QString sx = "/dev/ttyUSB"+num.setNum(n);
        ui->lblPort->setText(sx);
    }
}

void TestOwen::on_spbNum_valueChanged(int n)
{
    QString sx;
    QString num;
    if(ui->rdbSerial->isChecked())
        sx = "/dev/ttyS"+num.setNum(n);
    if(ui->rdbUSB->isChecked())
        sx = "/dev/ttyUSB"+num.setNum(n);
    ui->lblPort->setText(sx);
}

void TestOwen::on_cmdOpen_clicked()
{
    fd=open_port((const char*)(ui->lblPort->text().toStdString().data()),
                 (speed_t)B0);
    if(fd==-1)
        ui->lblStat->setText(tr("Отсутсвует"));
    else
        ui->lblStat->setText(tr("Открыт"));
}

void TestOwen::on_cmdClose_clicked()
{
    int r=close_port(fd);
    if(r==0)
        ui->lblStat->setText(tr("Закрыт"));
    else
        ui->lblStat->setText(tr("Неопределен"));
}

void TestOwen::on_cmdConnect_clicked()
{
    speed_t spd = ui->cbxSpeed->currentIndex();
    int addr = ui->spbAddr->value();
    int idx = ui->spdIdx->value();
    port_set_speed(fd, spd);
    float val=0.0;
    int r = read_data(fd, addr, idx, &val, 12);
    printf("r=%d val=%f\n",r,val);
}
