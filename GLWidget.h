#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include "rubics.h"

class MyGLWidget: public QGLWidget
{
    Q_OBJECT;

     int xRot;
     int yRot;
     int zRot;

    //Cubik rubik;

    QPoint lastPos;
    QTimer *timer;

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

public:
    Cubik rubik;
    MyGLWidget(QWidget *parent=0);
    ~MyGLWidget();
    void SaveToFile(QString fn);
    void SaveToString(QString fn);
    void SaveTosolution(QString fn);
    void LoadFromFile(QString fn);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void layerup();   //   function here
    void layerdn();
    void fwaxis();
    void sdaxis();
    void upaxis();
    void startrotation();
    void startrotationcw();
    void randcubik();
    void start8rotation(QString A);
    void startfacerotation(QString A);
//private slots:
    void nextframe();
};
#endif // GLWIDGET_H
