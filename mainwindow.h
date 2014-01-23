#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "GLWidget.h"
#include "rubics.h"
#include "cube.h"
#include "Singmaster.h"
#include "solutions.h"
#include "Oppocross.h"


#include <QtTest/QTestEventList>


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MyGLWidget *GLW;
    MyGLWidget*GLWhint;
    MyGLWidget*GLWNEW;
    Cubik*CUBIKResult;

private slots:
    void on_actionLoad_activated();
    void on_actionSave_activated();
    void on_actionNew_activated();
    void on_actionAbout_activated();
    void on_actionAuthor_activated();
    void on_actionAbout_Qt_activated();
    void on_actionAbout_the_hint_activated();

    //void on_pushButton_clicked();
    //void on_widget_customContextMenuRequested(const QPoint &pos);
   // void on_pushButton_clicked();
//    void on_pushButton_2_clicked();
    void on_RandomButton_clicked();
    void on_CounterRotate_clicked();

    //void on_textlabel_linkActivated(const QString &link);

//   void on_ShowHintcheck_stateChanged(int arg1);

 //   void on_showtestresult_clicked();

//    void on_speedScrollBar_sliderMoved(int position);
    void on_R_Rotatebutton_clicked();
    void on_RotateButton_clicked();
    void on_finishhintbutton_clicked();
    void on_ShowHintButton_clicked();

    void on_speedSlider_valueChanged(int value);

//    void on_singmastercheck_toggled(bool checked);
//    void on_Oppocrosscheck_toggled(bool checked);
};

#endif // MAINWINDOW_H
