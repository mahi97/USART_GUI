#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "controltab.h"
#include "configtab.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    ControlTab* control;
    ConfigTab* config;

    QTabWidget* tabs;

};

#endif // MAINWINDOW_H
