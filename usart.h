#ifndef USART_H
#define USART_H

#include <QtSerialPort/QSerialPort>
#include <QTextStream>
#include <QTimer>
#include <QByteArray>
#include <QObject>

class USART : public QObject
{
    Q_OBJECT

public:
    USART(QSerialPort *serialPort, QObject *parent = 0);
    ~USART();

    void write(const QByteArray &writeData);

private slots:
    void handleBytesWritten(qint64 bytes);
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort     *m_serialPort;
    QByteArray      m_writeData;
    QTextStream     m_standardOutput;
    qint64          m_bytesWritten;
    QTimer          m_timer;
};

#endif // USART_H
