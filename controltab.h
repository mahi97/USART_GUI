#ifndef CONTROLTAB_H
#define CONTROLTAB_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QScrollBar>
#include <QDebug>
#include <QSpinBox>
#include <QTabWidget>


class ControlTab : public QWidget
{
    Q_OBJECT

public:
    ControlTab(QWidget *parent);

    static const int VALVE_COUNT = 3;
    static const int TIME_COUNT = 4;

private:
    QPushButton* valves[VALVE_COUNT];
    QLabel* valveLabels[VALVE_COUNT];

    QSpinBox* timeSpins[TIME_COUNT];
    QScrollBar* scrollBars[TIME_COUNT];

    QFrame* getVLine() {
        QFrame *f = new QFrame(); f->setFrameShape(QFrame::VLine); f->setFrameShadow(QFrame::Sunken);
        return f;
    }

    QFrame* getHLine() {
        QFrame *f = new QFrame(); f->setFrameShape(QFrame::HLine); f->setFrameShadow(QFrame::Sunken);
        return f;
    }

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

#endif // CONTROLTAB_H
