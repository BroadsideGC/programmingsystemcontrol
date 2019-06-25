#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QVector>

#ifdef __linux__
#include <sys/time.h>
#endif

#include "qcustomplot.h"
#include "blocks/gain/gain.h"
#include "control.h"
#include "plant.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void makePlot();

private:
    Ui::Widget *ui;
    QGridLayout *mainlayout;
    QCustomPlot *inputPlot;
    QCustomPlot *outputPlot;

    double startTime;
    double dt;

    QTimer * timer;
    QVector<double> time;
    QVector<double> input;
    QVector<double> output;


    // --------------------------
    // Add pointer to the object here
    // --------------------------
    gain *object;   // <=
    control object1;
    Plant *object2;
    //integrator intgr;
    // --------------------------
    // Add pointer to the object here
    // --------------------------
};

#endif // WIDGET_H
