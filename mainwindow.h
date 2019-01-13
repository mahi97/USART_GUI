#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "controltab.h"
#include "infotab.h"
#include "configtab.h"
#include "usart.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    ControlTab* control;
    InfoTab* info;
    ConfigTab* config;

    QTabWidget* tabs;

    USART* usart;

};

#endif // MAINWINDOW_H
