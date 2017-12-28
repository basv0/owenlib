/********************************************************************************
** Form generated from reading UI file 'testowen.ui'
**
** Created: Sat Jun 13 10:54:07 2015
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTOWEN_H
#define UI_TESTOWEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestOwen
{
public:
    QGroupBox *grpVid;
    QRadioButton *rdbSerial;
    QRadioButton *rdbUSB;
    QSpinBox *spbNum;
    QLabel *lblNum;
    QLabel *lblPort;
    QPushButton *cmdOpen;
    QLabel *lblStatNam;
    QLabel *lblStat;
    QPushButton *cmdClose;
    QComboBox *cbxSpeed;
    QSpinBox *spdIdx;
    QSpinBox *spbAddr;
    QLabel *lblSpeed;
    QLabel *lblAddr;
    QLabel *lblIdx;
    QPushButton *cmdConnect;

    void setupUi(QWidget *TestOwen)
    {
        if (TestOwen->objectName().isEmpty())
            TestOwen->setObjectName(QString::fromUtf8("TestOwen"));
        TestOwen->resize(697, 544);
        grpVid = new QGroupBox(TestOwen);
        grpVid->setObjectName(QString::fromUtf8("grpVid"));
        grpVid->setGeometry(QRect(40, 60, 131, 81));
        rdbSerial = new QRadioButton(grpVid);
        rdbSerial->setObjectName(QString::fromUtf8("rdbSerial"));
        rdbSerial->setGeometry(QRect(10, 20, 80, 21));
        rdbSerial->setChecked(true);
        rdbUSB = new QRadioButton(grpVid);
        rdbUSB->setObjectName(QString::fromUtf8("rdbUSB"));
        rdbUSB->setGeometry(QRect(10, 50, 70, 21));
        spbNum = new QSpinBox(TestOwen);
        spbNum->setObjectName(QString::fromUtf8("spbNum"));
        spbNum->setGeometry(QRect(40, 10, 51, 31));
        lblNum = new QLabel(TestOwen);
        lblNum->setObjectName(QString::fromUtf8("lblNum"));
        lblNum->setGeometry(QRect(100, 20, 66, 17));
        lblPort = new QLabel(TestOwen);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));
        lblPort->setGeometry(QRect(50, 160, 121, 31));
        QFont font;
        font.setPointSize(12);
        lblPort->setFont(font);
        cmdOpen = new QPushButton(TestOwen);
        cmdOpen->setObjectName(QString::fromUtf8("cmdOpen"));
        cmdOpen->setGeometry(QRect(270, 10, 112, 41));
        lblStatNam = new QLabel(TestOwen);
        lblStatNam->setObjectName(QString::fromUtf8("lblStatNam"));
        lblStatNam->setGeometry(QRect(430, 50, 81, 17));
        lblStat = new QLabel(TestOwen);
        lblStat->setObjectName(QString::fromUtf8("lblStat"));
        lblStat->setGeometry(QRect(530, 50, 131, 17));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lblStat->setFont(font1);
        cmdClose = new QPushButton(TestOwen);
        cmdClose->setObjectName(QString::fromUtf8("cmdClose"));
        cmdClose->setGeometry(QRect(270, 70, 112, 41));
        cbxSpeed = new QComboBox(TestOwen);
        cbxSpeed->setObjectName(QString::fromUtf8("cbxSpeed"));
        cbxSpeed->setGeometry(QRect(272, 140, 110, 27));
        spdIdx = new QSpinBox(TestOwen);
        spdIdx->setObjectName(QString::fromUtf8("spdIdx"));
        spdIdx->setGeometry(QRect(272, 220, 58, 27));
        spdIdx->setMaximum(7);
        spbAddr = new QSpinBox(TestOwen);
        spbAddr->setObjectName(QString::fromUtf8("spbAddr"));
        spbAddr->setGeometry(QRect(272, 180, 60, 27));
        spbAddr->setMaximum(1023);
        spbAddr->setSingleStep(8);
        lblSpeed = new QLabel(TestOwen);
        lblSpeed->setObjectName(QString::fromUtf8("lblSpeed"));
        lblSpeed->setGeometry(QRect(393, 146, 66, 17));
        lblAddr = new QLabel(TestOwen);
        lblAddr->setObjectName(QString::fromUtf8("lblAddr"));
        lblAddr->setGeometry(QRect(356, 187, 66, 17));
        lblIdx = new QLabel(TestOwen);
        lblIdx->setObjectName(QString::fromUtf8("lblIdx"));
        lblIdx->setGeometry(QRect(357, 225, 66, 17));
        cmdConnect = new QPushButton(TestOwen);
        cmdConnect->setObjectName(QString::fromUtf8("cmdConnect"));
        cmdConnect->setGeometry(QRect(490, 170, 140, 80));

        retranslateUi(TestOwen);

        cbxSpeed->setCurrentIndex(13);


        QMetaObject::connectSlotsByName(TestOwen);
    } // setupUi

    void retranslateUi(QWidget *TestOwen)
    {
        TestOwen->setWindowTitle(QApplication::translate("TestOwen", "TestOwen", 0, QApplication::UnicodeUTF8));
        grpVid->setTitle(QString());
        rdbSerial->setText(QApplication::translate("TestOwen", "Serial", 0, QApplication::UnicodeUTF8));
        rdbUSB->setText(QApplication::translate("TestOwen", "USB", 0, QApplication::UnicodeUTF8));
        lblNum->setText(QApplication::translate("TestOwen", "\320\235\320\276\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        lblPort->setText(QApplication::translate("TestOwen", "/dev/ttyS0", 0, QApplication::UnicodeUTF8));
        cmdOpen->setText(QApplication::translate("TestOwen", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        lblStatNam->setText(QApplication::translate("TestOwen", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        lblStat->setText(QApplication::translate("TestOwen", "\320\275\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275", 0, QApplication::UnicodeUTF8));
        cmdClose->setText(QApplication::translate("TestOwen", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        cbxSpeed->clear();
        cbxSpeed->insertItems(0, QStringList()
         << QApplication::translate("TestOwen", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "75", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "134", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "150", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "300", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "1800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TestOwen", "230400", 0, QApplication::UnicodeUTF8)
        );
        lblSpeed->setText(QApplication::translate("TestOwen", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        lblAddr->setText(QApplication::translate("TestOwen", "\320\220\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        lblIdx->setText(QApplication::translate("TestOwen", "\320\230\320\275\320\264\320\265\320\272\321\201", 0, QApplication::UnicodeUTF8));
        cmdConnect->setText(QApplication::translate("TestOwen", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestOwen: public Ui_TestOwen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOWEN_H
