#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    tabs = new QTabWidget(this);
    setCentralWidget(tabs);

    control = new ControlTab(tabs);
    config  = new InfoTab(tabs);

    tabs->addTab(control, "Control");
    tabs->addTab(config, "Config");

    setFocus();



}

MainWindow::~MainWindow() {
}
