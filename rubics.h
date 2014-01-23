#ifndef RUBICS_H
#define RUBICS_H

#include <QString>

#include <QtTest/QTestEventList>

enum axis {UP,SD,FD}; // axes of rotation - up, side , forward

class Cubel // class for cube element
{
    double a; // half size of face
    double chamfer; // size of chamfer
    double space; // scale coeficient of cube
    int top,bottom,left,right,front,back; // colors of faces
    bool faces; // faces is visible?
    bool chamfers; // chamfers is visible?
public:
    int selected; // element is selected (white)?


    Cubel();
    void reset(); // return colors of faces to initial state

    ///////// Rotation of faces
    void rotateup(); //conterclockwise
    void rotatefd();
    void rotatesd();
    void rotateupcw(); //clockwise
    void rotatefdcw();
    void rotatesdcw();

    void draw(); // drawing

    QString tostring(); //something like serialization
    QString tofront();
    QString toleft();
    QString toback();
    QString toright();
    QString totop();
    QString tobottom();
    void fromstring(QString s);
};

class Cubik
{
    Cubel body[3][3][3]; // elements of cube
    int selecth; // selected layer
    axis selectax; // selected axis of rotation
    double selectangle; // angle of selected layer (for animation)
   // int animation; // while animation is on, we can't make any another animation (rotation)
    bool cw;


    void reselectbody(); // when we change axis or layer cubels must change colors of chamfers

    void drawuplayer(int h); // we must have funtions for drawing one selected layer normal to every axis
    void drawsdlayer(int h);
    void drawfdlayer(int h);

    void rotateup(); // rotation of selected layer arount vertical axis (y)
    void rotatefd(); // around fordward axis (z)
    void rotatesd(); // around side axis (x)
    void rotateupcw();
    void rotatefdcw(); // around fordward axis (z)
    void rotatesdcw();
public:
    Cubik();
    double speed;
     int animation; // while animation is on, we can't make any another animation (rotation)
    void selax(axis a); // change selected axis
    void selh(int dif); // change selected layer
    void resetchanges(); // assembles cubic into start position
    void draw(); // draws cube layers along selected axis
    void drawscanning(); // draws scanning of text
    void startanimation(); // sets initial animation values
    void startanimationcw();
    void animationframe(); // change state of cubic for next frame
    void randomize();
    QString tostring();
    QString tooutput();
    void fromstring(QString s);
    void start8rotation(QString A);
    void startfacerotation(QString A);
};

#endif // RUBICS_H
