#include "controltab.h"


ControlTab::ControlTab(QWidget *parent) : QWidget(parent) {

    valveLabels[0] = new QLabel("Input"  );
    valveLabels[1] = new QLabel("Output" );
    valveLabels[2] = new QLabel("Diafrag");

    valves[0] = new QPushButton("Off");
    valves[1] = new QPushButton("Off");
    valves[2] = new QPushButton("Off");

    QVBoxLayout* valvesLayouts[3];
    for (auto& l : valvesLayouts) {
        l = new QVBoxLayout;
    }
    for (int i = 0; i < VALVE_COUNT; i++) {
        valvesLayouts[i]->addWidget(valveLabels[i], 0, Qt::AlignCenter);
        valvesLayouts[i]->addWidget(valves[i], 0, Qt::AlignCenter);
        valvesValues[i] = false;
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

    QHBoxLayout* btns = new QHBoxLayout;
    def = new QPushButton("Default");
    send = new QPushButton("Send!");
    btns->addWidget(def);
    btns->addWidget(send);



    QLabel* header = new QLabel("USART GUI V0.1", this);
    all->addWidget(header, 0, Qt::AlignCenter);
    all->addWidget(getHLine());
    all->addLayout(main);
    all->addWidget(getHLine());
    all->addLayout(scroll);
    all->addWidget(getHLine());
    all->addLayout(btns);
    setLayout(all);

    connect(valves[0], SIGNAL(clicked(bool)), this, SLOT(toggleInput(bool)));
    connect(valves[1], SIGNAL(clicked(bool)), this, SLOT(toggleOutput(bool)));
    connect(valves[2], SIGNAL(clicked(bool)), this, SLOT(toggleDiaphrag(bool)));

    connect(scrollBars[0], SIGNAL(valueChanged(int)), this, SLOT(changeValueT0(int)));
    connect(scrollBars[1], SIGNAL(valueChanged(int)), this, SLOT(changeValueT1(int)));
    connect(scrollBars[2], SIGNAL(valueChanged(int)), this, SLOT(changeValueT2(int)));
    connect(scrollBars[3], SIGNAL(valueChanged(int)), this, SLOT(changeValueT3(int)));

    connect(timeSpins[0], SIGNAL(valueChanged(int)), this, SLOT(changeValueS0(int)));
    connect(timeSpins[1], SIGNAL(valueChanged(int)), this, SLOT(changeValueS1(int)));
    connect(timeSpins[2], SIGNAL(valueChanged(int)), this, SLOT(changeValueS2(int)));
    connect(timeSpins[3], SIGNAL(valueChanged(int)), this, SLOT(changeValueS3(int)));

    connect(def, SIGNAL(clicked(bool)), this, SLOT(defaultValue(bool)));
    connect(send, SIGNAL(clicked(bool)), this, SLOT(sendData(bool)));

}

void ControlTab::toggleBtn(QPushButton *btn) {
    if (btn->text() == "On") btn->setText("Off");
    else btn->setText("On");
}

void ControlTab::changeValueSpin(QSpinBox *spin, int value) {
    spin->setValue(value);
}

void ControlTab::changeValueScroll(QScrollBar *bar, int value) {
    bar->setValue(value);
}

char* ControlTab::encode(bool *_valves, int *_times) {
    char output[VALVE_COUNT + TIME_COUNT + 1];
    output[0] = 0x99;
    for (int i = 0; i < TIME_COUNT; i++) output[i + 1] = static_cast<unsigned char>(_times[i] >> 2);
    for (int i = 0; i < VALVE_COUNT; i++) output[i + TIME_COUNT + 1] = static_cast<unsigned char>(_valves[i]);

    return output;
}

void ControlTab::defaultValue(bool b) {
    if (valvesValues[0]) {
        toggleInput(false);
    }
    if (valvesValues[1]) {
        toggleOutput(false);
    }
    if (valvesValues[2]) {
        toggleDiaphrag(false);
    }

    for (int i = 0; i < TIME_COUNT; i++) {
        timeSpins[i]->setValue(0);
        scrollBars[i]->setValue(0);
    }

}

void ControlTab::sendData(bool b) {
    emit write(encode(valvesValues, timeValues));
}

void ControlTab::toggleInput(bool b) {
    toggleBtn(valves[0]);
    valvesValues[0] = !valvesValues[0];
}

void ControlTab::toggleOutput(bool b) {
    toggleBtn(valves[1]);
    valvesValues[1] = !valvesValues[1];

}

void ControlTab::toggleDiaphrag(bool b) {
    toggleBtn(valves[2]);
    valvesValues[2] = !valvesValues[2];

}

void ControlTab::changeValueT0(int i) {
    changeValueSpin(timeSpins[0], i);
    timeValues[0] = i;
}

void ControlTab::changeValueT1(int i) {
    changeValueSpin(timeSpins[1], i);
    timeValues[1] = i;

}

void ControlTab::changeValueT2(int i) {
    changeValueSpin(timeSpins[2], i);
    timeValues[2] = i;

}

void ControlTab::changeValueT3(int i) {
    changeValueSpin(timeSpins[3], i);
    timeValues[3] = i;

}

void ControlTab::changeValueS0(int i) {
    changeValueScroll(scrollBars[0], i);
}

void ControlTab::changeValueS1(int i) {
    changeValueScroll(scrollBars[1], i);
}

void ControlTab::changeValueS2(int i) {
    changeValueScroll(scrollBars[2], i);
}

void ControlTab::changeValueS3(int i) {
    changeValueScroll(scrollBars[3], i);
}

