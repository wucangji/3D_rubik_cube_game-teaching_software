/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 15 11:35:40 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave_Image;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionAuthor;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionAbout_the_hint;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *testoutput;
    QLineEdit *InputRotateName;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *speedSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *RandomButton;
    QPushButton *ShowHintButton;
    QPushButton *SelectUPAxisButton;
    QPushButton *SelectFDAxisButton;
    QPushButton *SelectSDAxisButton;
    QPushButton *PreviousLayerButton;
    QPushButton *NextLayerButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *R_Rotatebutton;
    QPushButton *CounterRotate;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *finishhintbutton;
    QPushButton *RotateButton;
    QCheckBox *singmastercheck;
    QCheckBox *Oppocrosscheck;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(675, 455);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../\320\240\320\276\320\261\320\276\321\207\320\270\320\271 \321\201\321\202\321\226\320\273/cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave_Image = new QAction(MainWindow);
        actionSave_Image->setObjectName(QString::fromUtf8("actionSave_Image"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionAuthor = new QAction(MainWindow);
        actionAuthor->setObjectName(QString::fromUtf8("actionAuthor"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionAbout_the_hint = new QAction(MainWindow);
        actionAbout_the_hint->setObjectName(QString::fromUtf8("actionAbout_the_hint"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 130, 181, 141));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        testoutput = new QLabel(centralWidget);
        testoutput->setObjectName(QString::fromUtf8("testoutput"));
        testoutput->setGeometry(QRect(20, 80, 271, 31));
        InputRotateName = new QLineEdit(centralWidget);
        InputRotateName->setObjectName(QString::fromUtf8("InputRotateName"));
        InputRotateName->setGeometry(QRect(187, 41, 221, 27));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(250, 120, 401, 251));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        speedSlider = new QSlider(centralWidget);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setGeometry(QRect(30, 280, 171, 29));
        speedSlider->setMinimum(4);
        speedSlider->setMaximum(20);
        speedSlider->setValue(10);
        speedSlider->setOrientation(Qt::Horizontal);
        speedSlider->setTickInterval(5);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 310, 191, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 101, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 142, 17));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 10, 633, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        RandomButton = new QPushButton(layoutWidget);
        RandomButton->setObjectName(QString::fromUtf8("RandomButton"));
        RandomButton->setMinimumSize(QSize(0, 27));

        horizontalLayout_3->addWidget(RandomButton);

        ShowHintButton = new QPushButton(layoutWidget);
        ShowHintButton->setObjectName(QString::fromUtf8("ShowHintButton"));

        horizontalLayout_3->addWidget(ShowHintButton);

        SelectUPAxisButton = new QPushButton(layoutWidget);
        SelectUPAxisButton->setObjectName(QString::fromUtf8("SelectUPAxisButton"));
        SelectUPAxisButton->setMinimumSize(QSize(0, 27));

        horizontalLayout_3->addWidget(SelectUPAxisButton);

        SelectFDAxisButton = new QPushButton(layoutWidget);
        SelectFDAxisButton->setObjectName(QString::fromUtf8("SelectFDAxisButton"));
        SelectFDAxisButton->setMinimumSize(QSize(0, 27));

        horizontalLayout_3->addWidget(SelectFDAxisButton);

        SelectSDAxisButton = new QPushButton(layoutWidget);
        SelectSDAxisButton->setObjectName(QString::fromUtf8("SelectSDAxisButton"));
        SelectSDAxisButton->setMinimumSize(QSize(0, 27));

        horizontalLayout_3->addWidget(SelectSDAxisButton);

        PreviousLayerButton = new QPushButton(layoutWidget);
        PreviousLayerButton->setObjectName(QString::fromUtf8("PreviousLayerButton"));
        PreviousLayerButton->setMinimumSize(QSize(0, 27));

        horizontalLayout_3->addWidget(PreviousLayerButton);

        NextLayerButton = new QPushButton(layoutWidget);
        NextLayerButton->setObjectName(QString::fromUtf8("NextLayerButton"));
        NextLayerButton->setMinimumSize(QSize(0, 27));

        horizontalLayout_3->addWidget(NextLayerButton);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(470, 40, 178, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        R_Rotatebutton = new QPushButton(layoutWidget1);
        R_Rotatebutton->setObjectName(QString::fromUtf8("R_Rotatebutton"));

        horizontalLayout_4->addWidget(R_Rotatebutton);

        CounterRotate = new QPushButton(layoutWidget1);
        CounterRotate->setObjectName(QString::fromUtf8("CounterRotate"));
        CounterRotate->setMinimumSize(QSize(0, 27));

        horizontalLayout_4->addWidget(CounterRotate);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(430, 70, 221, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        finishhintbutton = new QPushButton(layoutWidget2);
        finishhintbutton->setObjectName(QString::fromUtf8("finishhintbutton"));

        horizontalLayout_5->addWidget(finishhintbutton);

        RotateButton = new QPushButton(layoutWidget2);
        RotateButton->setObjectName(QString::fromUtf8("RotateButton"));
        RotateButton->setMinimumSize(QSize(0, 27));

        horizontalLayout_5->addWidget(RotateButton);

        singmastercheck = new QCheckBox(centralWidget);
        singmastercheck->setObjectName(QString::fromUtf8("singmastercheck"));
        singmastercheck->setGeometry(QRect(40, 330, 161, 22));
        Oppocrosscheck = new QCheckBox(centralWidget);
        Oppocrosscheck->setObjectName(QString::fromUtf8("Oppocrosscheck"));
        Oppocrosscheck->setGeometry(QRect(40, 360, 171, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 675, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        menuHelp->addAction(actionAuthor);
        menuHelp->addAction(actionAbout_the_hint);

        retranslateUi(MainWindow);
        QObject::connect(finishhintbutton, SIGNAL(clicked()), ShowHintButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Rubics cube", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionSave_Image->setText(QApplication::translate("MainWindow", "Save Image", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionAuthor->setText(QApplication::translate("MainWindow", "Author", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionAbout_the_hint->setText(QApplication::translate("MainWindow", "About the hint", 0, QApplication::UnicodeUTF8));
        testoutput->setText(QApplication::translate("MainWindow", "Your Hint will show here", 0, QApplication::UnicodeUTF8));
        InputRotateName->setText(QString());
        label->setText(QApplication::translate("MainWindow", "min             speed               max", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Hint Window", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Input your command:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        RandomButton->setToolTip(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        RandomButton->setStatusTip(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        RandomButton->setText(QApplication::translate("MainWindow", "Random", 0, QApplication::UnicodeUTF8));
        RandomButton->setShortcut(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ShowHintButton->setToolTip(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        ShowHintButton->setStatusTip(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        ShowHintButton->setText(QApplication::translate("MainWindow", "ShowHint", 0, QApplication::UnicodeUTF8));
        ShowHintButton->setShortcut(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SelectUPAxisButton->setToolTip(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        SelectUPAxisButton->setStatusTip(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        SelectUPAxisButton->setText(QApplication::translate("MainWindow", "Top", 0, QApplication::UnicodeUTF8));
        SelectUPAxisButton->setShortcut(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SelectFDAxisButton->setToolTip(QApplication::translate("MainWindow", "F", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        SelectFDAxisButton->setStatusTip(QApplication::translate("MainWindow", "F", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        SelectFDAxisButton->setText(QApplication::translate("MainWindow", "Front", 0, QApplication::UnicodeUTF8));
        SelectFDAxisButton->setShortcut(QApplication::translate("MainWindow", "F", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SelectSDAxisButton->setToolTip(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        SelectSDAxisButton->setStatusTip(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        SelectSDAxisButton->setText(QApplication::translate("MainWindow", "Side", 0, QApplication::UnicodeUTF8));
        SelectSDAxisButton->setShortcut(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        PreviousLayerButton->setToolTip(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        PreviousLayerButton->setStatusTip(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        PreviousLayerButton->setText(QApplication::translate("MainWindow", "UP", 0, QApplication::UnicodeUTF8));
        PreviousLayerButton->setShortcut(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        NextLayerButton->setToolTip(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        NextLayerButton->setStatusTip(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        NextLayerButton->setText(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
        NextLayerButton->setShortcut(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        R_Rotatebutton->setToolTip(QApplication::translate("MainWindow", "G", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        R_Rotatebutton->setStatusTip(QApplication::translate("MainWindow", "G", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        R_Rotatebutton->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
        R_Rotatebutton->setShortcut(QApplication::translate("MainWindow", "G", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CounterRotate->setToolTip(QApplication::translate("MainWindow", "space", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        CounterRotate->setStatusTip(QApplication::translate("MainWindow", "space", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        CounterRotate->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        CounterRotate->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        finishhintbutton->setToolTip(QApplication::translate("MainWindow", "H", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        finishhintbutton->setStatusTip(QApplication::translate("MainWindow", "H", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        finishhintbutton->setText(QApplication::translate("MainWindow", "Finish Hint steps", 0, QApplication::UnicodeUTF8));
        finishhintbutton->setShortcut(QApplication::translate("MainWindow", "H", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        RotateButton->setToolTip(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        RotateButton->setStatusTip(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        RotateButton->setText(QApplication::translate("MainWindow", "Rotate'", 0, QApplication::UnicodeUTF8));
        RotateButton->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        singmastercheck->setText(QApplication::translate("MainWindow", "SingMaster Method", 0, QApplication::UnicodeUTF8));
        Oppocrosscheck->setText(QApplication::translate("MainWindow", "OppoCross Method", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
