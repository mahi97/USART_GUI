#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    tabs = new QTabWidget(this);
    setCentralWidget(tabs);

    setFocus();

    valveLabels[0] = new QLabel("Input"  );
    valveLabels[1] = new QLabel("Output" );
    valveLabels[2] = new QLabel("Diafrag");

    valves[0] = new QPushButton("On");
    valves[1] = new QPushButton("On");
    valves[2] = new QPushButton("On");

    QVBoxLayout* valvesLayouts[3];
    for (auto& l : valvesLayouts) {
        l = new QVBoxLayout;
    }
    for (int i = 0; i < VALVE_COUNT; i++) {
        valvesLayouts[i]->addWidget(valveLabels[i], 0, Qt::AlignCenter);
        valvesLayouts[i]->addWidget(valves[i], 0, Qt::AlignCenter);
    }

    QVBoxLayout* all = new QVBoxLayout;
    QHBoxLayout* main = new QHBoxLayout;
    for (auto& layout : valvesLayouts) {
        main->addWidget(getVLine());
        main->addLayout(layout);
        main->addWidget(getVLine());

    }

    QVBoxLayout* scroll = new QVBoxLayout;
    QLabel* t[4];
    QHBoxLayout* hb[4];
    for (int i = 0; i < 4; i++) {
        t[i] = new QLabel(QString("T_%1").arg(i));
        scrollBars[i] = new QScrollBar(Qt::Horizontal);
        scrollBars[i]->setMaximum(1000);
        hb[i] = new QHBoxLayout;
        timeSpins[i] = new QSpinBox();
        timeSpins[i]->setMinimum(0);
        timeSpins[i]->setMaximum(1000);
        timeSpins[i]->setValue(scrollBars[i]->value());
        scroll->addLayout(hb[i]);
        hb[i]->addWidget(t[i]);
        hb[i]->addWidget(scrollBars[i]);
        hb[i]->addWidget(timeSpins[i]);
    }



    QWidget* w = new QWidget(this);
    QLabel* header = new QLabel("USART GUI V0.1", this);
    all->addWidget(header, 0, Qt::AlignCenter);
    all->addWidget(getHLine());
    all->addLayout(main);
    all->addWidget(getHLine());
    all->addLayout(scroll);
    w->setLayout(all);
    QWidget* w2 = new QWidget(this);

    tabs->addTab(w, "Control");
    tabs->addTab(w2, "Config");


    connect(valves[0], SIGNAL(clicked(bool)), this, SLOT(toggleInput(bool)));
    connect(valves[1], SIGNAL(clicked(bool)), this, SLOT(toggleOutput(bool)));
    connect(valves[2], SIGNAL(clicked(bool)), this, SLOT(toggleDiafrag(bool)));

    connect(scrollBars[0], SIGNAL(valueChanged(int)), this, SLOT(changeValueT0(int)));
    connect(scrollBars[1], SIGNAL(valueChanged(int)), this, SLOT(changeValueT1(int)));
    connect(scrollBars[2], SIGNAL(valueChanged(int)), this, SLOT(changeValueT2(int)));
    connect(scrollBars[3], SIGNAL(valueChanged(int)), this, SLOT(changeValueT3(int)));

    connect(timeSpins[0], SIGNAL(valueChanged(int)), this, SLOT(changeValueS0(int)));
    connect(timeSpins[1], SIGNAL(valueChanged(int)), this, SLOT(changeValueS1(int)));
    connect(timeSpins[2], SIGNAL(valueChanged(int)), this, SLOT(changeValueS2(int)));
    connect(timeSpins[3], SIGNAL(valueChanged(int)), this, SLOT(changeValueS3(int)));

}

MainWindow::~MainWindow() {
}

QFrame *MainWindow::getVLine(QWidget* parent) {
    QFrame *f = new QFrame(parent); f->setFrameShape(QFrame::VLine); f->setFrameShadow(QFrame::Sunken);
    return f;
}

QFrame *MainWindow::getHLine(QWidget* parent) {
    QFrame *f = new QFrame(parent); f->setFrameShape(QFrame::HLine); f->setFrameShadow(QFrame::Sunken);
    return f;
}

void MainWindow::toggleBtn(QPushButton *btn) {
    if (btn->text() == "On") btn->setText("Off");
    else btn->setText("On");
}

void MainWindow::changeValueSpin(QSpinBox *spin, int value) {
    spin->setValue(value);
}

void MainWindow::changeValueScroll(QScrollBar *bar, int value) {
    bar->setValue(value);
}

void MainWindow::toggleInput(bool b) {
    toggleBtn(valves[0]);
}

void MainWindow::toggleOutput(bool b) {
    toggleBtn(valves[1]);
}

void MainWindow::toggleDiafrag(bool b) {
    toggleBtn(valves[2]);
}

void MainWindow::changeValueT0(int i) {
    changeValueSpin(timeSpins[0], i);
}

void MainWindow::changeValueT1(int i) {
    changeValueSpin(timeSpins[1], i);
}

void MainWindow::changeValueT2(int i) {
    changeValueSpin(timeSpins[2], i);
}

void MainWindow::changeValueT3(int i) {
    changeValueSpin(timeSpins[3], i);
}

void MainWindow::changeValueS0(int i) {
    changeValueScroll(scrollBars[0], i);
}

void MainWindow::changeValueS1(int i) {
    changeValueScroll(scrollBars[1], i);
}

void MainWindow::changeValueS2(int i) {
    changeValueScroll(scrollBars[2], i);
}

void MainWindow::changeValueS3(int i) {
    changeValueScroll(scrollBars[3], i);
}
