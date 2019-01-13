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

class ConfigTab : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigTab(QWidget *parent = 0);

    QSerialPort* serialPort;

signals:

public slots:
};

#endif // CONFIGTAB_H
