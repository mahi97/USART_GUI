#ifndef INFOTAB_H
#define INFOTAB_H

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

#endif // INFOTAB_H
