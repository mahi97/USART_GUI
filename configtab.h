#ifndef CONFIGTAB_H
#define CONFIGTAB_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QScrollBar>
#include <QDebug>
#include <QSpinBox>
#include <QTabWidget>
#include <QSerialPortInfo>
#include <QScrollArea>
#include <QComboBox>
#include <QSerialPort>
#include <QDebug>

class ConfigTab : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigTab(QWidget *parent = 0);

    QSerialPort* serialPort;
private:
    QComboBox* comboBaud;
    QComboBox* combo;
private slots:
    void updatePort(int i);
    void updateBaud(int i);
};

#endif // CONFIGTAB_H
