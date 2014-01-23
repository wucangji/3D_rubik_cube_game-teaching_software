#include "GLWidget.h"
#include <GL/glu.h>
#include <QMessageBox>
#include <QFile>
//#include <QtOpenGL/qgl.h>
#include <QTextStream>
#include <QDebug>
#include <QtTest/QTestEventList>



 QTestEventList events;

void normalizeAngle(int *angle)
 {
     while (*angle < 0)
         *angle += 360 * 16;
     while (*angle > 360 * 16)
         *angle -= 360 * 16;
 }

MyGLWidget::MyGLWidget(QWidget *parent) : QGLWidget(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextframe()));
    timer->start(20);
}
MyGLWidget::~MyGLWidget()
{
}

void MyGLWidget::SaveToFile(QString fn)
{
    QFile data(fn);
    if(data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out << xRot << "\n";
        out << yRot << "\n";
        out << zRot << "\n";
        out << rubik.tostring();
    }
}

void MyGLWidget::SaveTosolution(QString fn)
{
    QFile data(fn);
    if(data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out << rubik.tooutput();
    }
}

void MyGLWidget::SaveToString(QString fn)
{

        //QTextStream out(&data);

        fn+=xRot;
        fn+="\n";
        fn+=yRot;
        fn+="\n";
        fn+=zRot;
        fn+="\n";

        fn+= rubik.tostring();

}


void MyGLWidget::LoadFromFile(QString fn)
{
    QFile data(fn);
    if(data.open(QFile::ReadOnly))
    {
        QTextStream in(&data);
        QString tmp;
        in >> xRot;
        in >> yRot;
        in >> zRot;
        in >> tmp;
        rubik.fromstring(tmp);
    }
}

void MyGLWidget::initializeGL()
{
    glClearColor(0.03,0.2,0.03,0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void MyGLWidget::resizeGL(int width, int height)
{
    glViewport(0,0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-0.5, +0.5, +0.5, -0.5, 4.0, 15.0);
    gluPerspective(45,float(width)/(height+1),1,20);
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::paintGL()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -13.0);   //  change the size of the cube
    glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0);
    rubik.draw();
}
void MyGLWidget::mousePressEvent(QMouseEvent *event)
 {
     lastPos=event->pos();
 }

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
 {
     int dx = event->x() - lastPos.x();
     int dy = event->y() - lastPos.y();

     if (event->buttons() & Qt::LeftButton) {
         setXRotation(xRot + 8 * dy);
         setYRotation(yRot + 8 * dx);
     } else if (event->buttons() & Qt::RightButton) {
         setXRotation(xRot + 8 * dy);
         setZRotation(zRot + 8 * dx);
     }
     lastPos = event->pos();
 }

 void MyGLWidget::setXRotation(int angle)
 {
     normalizeAngle(&angle);
     if (angle != xRot) {
         xRot = angle;
         updateGL();
     }
 }

 void MyGLWidget::setYRotation(int angle)
 {
     normalizeAngle(&angle);
     if (angle != yRot) {
         yRot = angle;
         updateGL();
     }
 }

 void MyGLWidget::setZRotation(int angle)
 {
     normalizeAngle(&angle);
     if (angle != zRot) {
         zRot = angle;
         updateGL();
     }
 }

 void MyGLWidget::nextframe()
 {
     rubik.animationframe();
     updateGL();
 }

 void MyGLWidget::layerdn()
 {
     rubik.selh(1);
     updateGL();
 }
 void MyGLWidget::layerup()
 {
     rubik.selh(-1);
     updateGL();
 }
 void MyGLWidget::fwaxis()
 {
     rubik.selax(FD);
     updateGL();
 }
 void MyGLWidget::sdaxis()
 {
      rubik.selax(SD);
      updateGL();
 }
 void MyGLWidget::upaxis()
 {
    rubik.selax(UP);
    updateGL();
 }
void MyGLWidget::startrotation()
{
    rubik.startanimation();
    updateGL();
}

void MyGLWidget::startrotationcw()  //clockwise
{
    //rubik.startanimationcw();
    rubik.startanimationcw();
    updateGL();  // return the new color
}

void MyGLWidget::randcubik()
{
    rubik.randomize();
    updateGL();
}

void MyGLWidget::start8rotation(QString A)
{
    rubik.start8rotation(A);
    updateGL();
}

void MyGLWidget::startfacerotation(QString A)
{


  //  if(A=="X"||A=="x"){
      rubik.startfacerotation(A);
     updateGL();


}
