#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    tabs = new QTabWidget(this);
    setCentralWidget(tabs);

    control = new ControlTab(tabs);
    info  = new InfoTab(tabs);
    config = new ConfigTab(tabs);

    tabs->addTab(control, "Control");
    tabs->addTab(config, "Config");
    tabs->addTab(info, "Info");

    setFocus();

    usart = new USART(config->serialPort, this);

    connect(control, SIGNAL(write(char*)), this, SLOT(write(char*)));
}

MainWindow::~MainWindow() {
}

void MainWindow::write(char *data) {
    usart->write(QByteArray(data, 8));
}
