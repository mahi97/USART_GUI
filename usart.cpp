#include "usart.h"

USART::USART(QSerialPort *serialPort, QObject *parent)
    : QObject(parent)
    , m_serialPort(serialPort)
    , m_standardOutput(stdout)
    , m_bytesWritten(0)
{
    m_timer.setSingleShot(true);
    connect(m_serialPort, SIGNAL(bytesWritten(qint64)), this, SLOT(handleBytesWritten(qint64)));
    connect(m_serialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &USART::handleError);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

USART::~USART()
{
}

void USART::handleBytesWritten(qint64 bytes)
{
    m_bytesWritten += bytes;
    if (m_bytesWritten == m_writeData.size()) {
        m_bytesWritten = 0;
        m_standardOutput << QObject::tr("Data successfully sent to port %1").arg(m_serialPort->portName()) << endl;
    }
}

void USART::handleTimeout()
{
    m_standardOutput << QObject::tr("Operation timed out for port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
}

void USART::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::WriteError) {
        m_standardOutput << QObject::tr("An I/O error occurred while writing the data to port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
    }
}

void USART::write(const QByteArray &writeData)
{
    m_writeData = writeData;

    qint64 bytesWritten = m_serialPort->write(writeData);

    if (bytesWritten == -1) {
        m_standardOutput << QObject::tr("Failed to write the data to port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
    } else if (bytesWritten != m_writeData.size()) {
        m_standardOutput << QObject::tr("Failed to write all the data to port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
    }

    m_timer.start(5000);
}
