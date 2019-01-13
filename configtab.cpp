#include "configtab.h"

ConfigTab::ConfigTab(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout;

    QHBoxLayout* portLay = new QHBoxLayout;
    QLabel* port = new QLabel("Port: ");
    QComboBox* combo = new QComboBox(this);
    const auto infos = QSerialPortInfo::availablePorts();
    for (const auto& info : infos) {
      combo->addItem(info.portName(), QVariant(info.systemLocation()));
    }
    portLay->addWidget(port);
    portLay->addWidget(combo);

    QHBoxLayout* baudLay = new QHBoxLayout;
    QLabel* baud = new QLabel("Baud Rate: ");
    QComboBox* comboBaud = new QComboBox(this);
    comboBaud->addItem(QString("1200")  , QVariant(1200));
    comboBaud->addItem(QString("2400")  , QVariant(2400));
    comboBaud->addItem(QString("4800")  , QVariant(4800));
    comboBaud->addItem(QString("9600")  , QVariant(9600));
    comboBaud->addItem(QString("19200") , QVariant(19200));
    comboBaud->addItem(QString("38400") , QVariant(38400));
    comboBaud->addItem(QString("57600") , QVariant(57600));
    comboBaud->addItem(QString("115200"), QVariant(115200));
    baudLay->addWidget(baud);
    baudLay->addWidget(comboBaud);

    layout->addLayout(portLay);
    layout->addLayout(baudLay);
    setLayout(layout);

    serialPort = new QSerialPort(this);
    serialPort->setBaudRate(comboBaud->currentData().toInt());
    serialPort->setPortName(combo->currentData().toString());


}
