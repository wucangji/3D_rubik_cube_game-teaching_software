#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
 #include <QStringList>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GLW = new MyGLWidget();
    GLWhint= new MyGLWidget();
    GLWNEW= new MyGLWidget();
   ui->horizontalLayout->addWidget(GLWhint);

   ui->horizontalLayout_2->addWidget(GLWNEW);
    connect(ui->NextLayerButton,SIGNAL(clicked()),GLWNEW,SLOT(layerup()));
    connect(ui->PreviousLayerButton,SIGNAL(clicked()),GLWNEW,SLOT(layerdn()));
    connect(ui->SelectFDAxisButton,SIGNAL(clicked()),GLWNEW,SLOT(fwaxis()));
    connect(ui->SelectSDAxisButton,SIGNAL(clicked()),GLWNEW,SLOT(sdaxis()));
    connect(ui->SelectUPAxisButton,SIGNAL(clicked()),GLWNEW,SLOT(upaxis()));
   // connect(ui->RotateButton,SIGNAL(clicked()),GLW,SLOT(startrotation()));




   // connect(ui->RandomButton,SIGNAL(clicked()),GLW,SLOT(randcubik()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_Qt_activated()
{
    QMessageBox::aboutQt(this,"About Qt");
}

void MainWindow::on_actionAuthor_activated()
{
    QMessageBox::about(this,"About author","Tianye Ma,  Cangji Wu, Dan Shao ");
}

void MainWindow::on_actionAbout_activated()
{
    QMessageBox::about(this,"About","<h1>Rubics Cube</h1>Model of Rubics cube using OpenGL and QT");
}



void MainWindow::on_actionAbout_the_hint_activated()
{
    QMessageBox::about(this,"About the hint "," <h1>About the hint </h1> <a href='http://www.rubiks.com/solving-center/solve_rubiks_3x3_cube.php'>Show the hint website </a>");
}



void MainWindow::on_actionNew_activated()
{
    GLWNEW->randcubik();
}




void MainWindow::on_actionSave_activated()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save cubik"), "/home/cangjiwu/Desktop", tr(""));
    GLWNEW->SaveToFile(filename);
}

void MainWindow::on_actionLoad_activated()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Load cubik"), "/home/cangjiwu/Desktop", tr(""));
    GLWNEW->LoadFromFile(filename);
    GLWhint->LoadFromFile(filename);
}





void MainWindow::on_RandomButton_clicked()
{
    GLWNEW->randcubik();

    GLWNEW->SaveToFile("/home/cangjiwu/Desktop/temp");
    GLWhint->LoadFromFile("/home/cangjiwu/Desktop/temp");
}

void MainWindow::on_CounterRotate_clicked()
{
    GLWNEW->startrotationcw();
}

void MainWindow::on_RotateButton_clicked()
{
    GLWNEW->startrotation();
}



/*
void MainWindow::on_textlabel_linkActivated(const QString &link)
{
    QString text="da shabi";
    ui->textlabel->setText(text);
}

void MainWindow::on_pushButton_2_stateChanged()
{
    // QMessageBox::about(this,"About author","Cangji Wu,  Tianye Ma");
    QString text="da shabi";
    ui->textlabel->setText(text);
}
*/

/*
void MainWindow::on_ShowHintcheck_stateChanged(int arg1)
{
    if (arg1==0){
        QString text="you can get hint by click the hintbutton";
        ui->textlabel->setText(text);
    }else{
        ui->textlabel->setText("that's interesting!dashabi!");
    }
}
*/

/*
void MainWindow::on_showtestresult_clicked()
{
    QString text;
    //CUBIKResult = new Cubik();
    Cubik CUBIKResult;
    //GLW->SaveToFile("/home/cangjiwu/Desktop/temp");
    CUBIKResult=GLWNEW->rubik;
    text= CUBIKResult.tooutput();
    ui->testoutput->setText(text);

}


void MainWindow::on_speedScrollBar_sliderMoved(int position)
{
     GLW->rubik.speed=double(position);
}
*/
void MainWindow::on_R_Rotatebutton_clicked()
{
    QString A=ui->InputRotateName->text();

     QStringList list1 = A.split(" ", QString::SkipEmptyParts);
        QVector<QString> list2 = list1.toVector();
     for(int i=0;i<list2.size();i++){
         if(list2[i]=="U"|| list2[i]=="U'"|| list2[i]=="u"||list2[i]=="u'"||
                 list2[i]=="r"|| list2[i]=="R"|| list2[i]=="R'"|| list2[i]=="r'"||
                 list2[i]=="F"|| list2[i]=="F'"|| list2[i]=="f"|| list2[i]=="f'"||
                 list2[i]=="D"|| list2[i]=="d'"|| list2[i]=="d"||list2[i]=="D'"||
                 list2[i]=="L"|| list2[i]=="l"|| list2[i]=="L'"|| list2[i]=="l'"||
                 list2[i]=="B"|| list2[i]=="B'"|| list2[i]=="b"|| list2[i]=="b'"
                 ){
             GLWhint->start8rotation(list2[i]);
                    QTest::qWait(600);
         }

         else if (list2[i]=="X"||list2[i]=="x"||list2[i]=="Y"||list2[i]=="y"|| list2[i]=="Z"||list2[i]=="z"||
                  list2[i]=="X2"||list2[i]=="x2"||list2[i]=="Y2"||list2[i]=="y2"|| list2[i]=="Z2"||list2[i]=="z2"||
                  list2[i]=="X'"||list2[i]=="x'"||list2[i]=="Y'"||list2[i]=="y'"|| list2[i]=="Z'"||list2[i]=="z'"||
                  list2[i]=="b2"|| list2[i]=="B2" || list2[i]=="L2"||list2[i]=="l2"||
                 list2[i]=="D2"|| list2[i]=="d2"|| list2[i]=="f2"|| list2[i]=="F2"||
                  list2[i]=="R2"||list2[i]=="r2"|| list2[i]=="u2"|| list2[i]=="U2" ){

             GLWhint->startfacerotation(list2[i]);
             QTest::qWait(600);
         }
         else {

             QMessageBox::about(this,"ERROR!!","Wrong input order !! Please try again");
         }
     }

}



void MainWindow::on_finishhintbutton_clicked()
{
    QString hint;
    hint = ui->testoutput->text();

    QStringList list1 = hint.split(" ", QString::SkipEmptyParts);
       QVector<QString> list2 = list1.toVector();
    for(int i=0;i<list2.size();i++){
        if(list2[i]=="U"|| list2[i]=="U'"|| list2[i]=="u"||list2[i]=="u'"||
                list2[i]=="r"|| list2[i]=="R"|| list2[i]=="R'"|| list2[i]=="r'"||
                list2[i]=="F"|| list2[i]=="F'"|| list2[i]=="f"|| list2[i]=="f'"||
                list2[i]=="D"|| list2[i]=="d'"|| list2[i]=="d"||list2[i]=="D'"||
                list2[i]=="L"|| list2[i]=="l"|| list2[i]=="L'"|| list2[i]=="l'"||
                list2[i]=="B"|| list2[i]=="B'"|| list2[i]=="b"|| list2[i]=="b'"
                ){
            GLWhint->start8rotation(list2[i]);
                   QTest::qWait(600);
        }

        else if (list2[i]=="X"||list2[i]=="x"||list2[i]=="Y"||list2[i]=="y"|| list2[i]=="Z"||list2[i]=="z"||
                 list2[i]=="X2"||list2[i]=="x2"||list2[i]=="Y2"||list2[i]=="y2"|| list2[i]=="Z2"||list2[i]=="z2"||
                 list2[i]=="X'"||list2[i]=="x'"||list2[i]=="Y'"||list2[i]=="y'"|| list2[i]=="Z'"||list2[i]=="z'"||
                 list2[i]=="b2"|| list2[i]=="B2" || list2[i]=="L2"||list2[i]=="l2"||
                list2[i]=="D2"|| list2[i]=="d2"|| list2[i]=="f2"|| list2[i]=="F2"||
                 list2[i]=="R2"||list2[i]=="r2"|| list2[i]=="u2"|| list2[i]=="U2" ){

            GLWhint->startfacerotation(list2[i]);
        }
        else {

            QMessageBox::about(this,"ERROR!!","Wrong input order !! Please try again");
        }
    }


}

void MainWindow::on_ShowHintButton_clicked()
{

   // GLWNEW->SaveToFile("/home/cangjiwu/Desktop/temp");
   // GLWhint->LoadFromFile("/home/cangjiwu/Desktop/temp");

     if(ui->singmastercheck->checkState()==2 && ui->Oppocrosscheck->checkState()==2 ){
         QMessageBox::about(this,"ERROR!!", "<h1>Please pick just one method!</h1>");

     }

    else if(ui->singmastercheck->checkState()==2){

        QString text;

        Cubik CUBIKResult;

        CUBIKResult=GLWhint->rubik;
        text= CUBIKResult.tooutput();
        GLWhint->SaveTosolution("/home/cangjiwu/Desktop/statetemp");
        cube* RCPoint = new cube();
        RCPoint->readIn("/home/cangjiwu/Desktop/statetemp");

            solutions * sol=new Singmaster();

           // vector<string> a= sol->allSteps(*RCPoint);
            string a = sol->someSteps(*RCPoint);
            QString b = QString::fromStdString(a);

            QFont ft;
            ft.setPointSize(13);
            ui->testoutput->setFont(ft);


            QPalette pa;
            pa.setColor(QPalette::WindowText,Qt::blue);
            ui->testoutput->setPalette(pa);
            ui->testoutput->setText(b);

    }

    else if (ui->Oppocrosscheck->checkState()==2){

        QString text;

        Cubik CUBIKResult;

        CUBIKResult=GLWhint->rubik;
        text= CUBIKResult.tooutput();
        GLWhint->SaveTosolution("/home/cangjiwu/Desktop/statetemp");
        cube* RCPoint = new cube();
        RCPoint->readIn("/home/cangjiwu/Desktop/statetemp");

        solutions * sol=new Oppocross();

           // vector<string> a= sol->allSteps(*RCPoint);
            string a = sol->someSteps(*RCPoint);
            QString b = QString::fromStdString(a);

            QFont ft;
            ft.setPointSize(13);
            ui->testoutput->setFont(ft);


            QPalette pa;
            pa.setColor(QPalette::WindowText,Qt::blue);
            ui->testoutput->setPalette(pa);
            ui->testoutput->setText(b);

    }

    else{
    QMessageBox::about(this,"ERROR!!", "<h1>Please pick just method!</h1>");
    }
}



void MainWindow::on_speedSlider_valueChanged(int value)
{
             GLWhint->rubik.speed=double(value);
}




