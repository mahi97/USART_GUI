#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QScrollBar>
#include <QDebug>
#include <QSpinBox>
#include <QTabWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static const int VALVE_COUNT = 3;
    static const int TIME_COUNT = 4;

private:
    QFrame *getVLine(QWidget* parent = 0);
    QFrame *getHLine(QWidget* parent = 0);


    QTabWidget* tabs;

    QPushButton* valves[VALVE_COUNT];
    QLabel* valveLabels[VALVE_COUNT];

    QSpinBox* timeSpins[TIME_COUNT];
    QScrollBar* scrollBars[TIME_COUNT];


    void toggleBtn(QPushButton* btn);
    void changeValueSpin(QSpinBox *spin, int value);
    void changeValueScroll(QScrollBar *bar, int value);
private slots:
    void toggleInput(bool b);
    void toggleOutput(bool b);
    void toggleDiafrag(bool b);

    void changeValueT0(int i);
    void changeValueT1(int i);
    void changeValueT2(int i);
    void changeValueT3(int i);

    void changeValueS0(int i);
    void changeValueS1(int i);
    void changeValueS2(int i);
    void changeValueS3(int i);

};

#endif // MAINWINDOW_H
