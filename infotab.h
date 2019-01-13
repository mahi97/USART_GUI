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


class InfoTab : public QWidget
{
    Q_OBJECT

public:
    InfoTab(QWidget* parent);
};

#endif // CONFIGTAB_H
