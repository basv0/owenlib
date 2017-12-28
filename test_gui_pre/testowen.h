#ifndef TESTOWEN_H
#define TESTOWEN_H

#include <QWidget>

namespace Ui {
class TestOwen;
}

class TestOwen : public QWidget
{
    Q_OBJECT
    
public:
    explicit TestOwen(QWidget *parent = 0);
    ~TestOwen();
    
private slots:
    void on_rdbSerial_clicked(bool checked);

    void on_rdbUSB_clicked(bool checked);

    void on_spbNum_valueChanged(int arg1);

    void on_cmdOpen_clicked();

    void on_cmdClose_clicked();

    void on_cmdConnect_clicked();

private:
    Ui::TestOwen *ui;
    int fd;
};

#endif // TESTOWEN_H
