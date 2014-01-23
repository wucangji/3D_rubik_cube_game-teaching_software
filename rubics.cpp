#include "rubics.h"


#include <QGLWidget>
#include <QDebug>
#define NOR glNormal3d // I want write less
#define VER glVertex3d


void COL(int num) // set color of face, 0 - color of nonselected chamfer, 7 - color of selected chamfer
{                              //              white   yellow  red    orange    gree    blue
    const float colors[8][3]={{0.1,0.1,0.1}, {1,1,1},{1,1,0},{1,0,0},{1,0.5,0},{0,1,0},{0,0,1},{0.8,0.8,1}};
    glColor3f(colors[num][0],colors[num][1],colors[num][2]);
}

    Cubel::Cubel()
    {
        chamfers=true; // all initial settings
        faces=true;
        space=0.95;
        chamfer=0.1;
        a=1-chamfer;
        selected=0;
        front=1;
        left=2;
        back=3;
        right=4;
        top=5;
        bottom=6;    //   blue
    }
    void Cubel::reset() // return colors of faces to initial state
    {
        front=1;
        left=2;
        back=3;
        right=4;
        top=5;
        bottom=6;
    }

    ///////// Rotation of faces
    void Cubel::rotateup() //conterclockwise
    {
        int tmp=front;front=left;left=back;back=right;right=tmp;
    }
    void Cubel::rotatefd()
    {
        int tmp=left;left=top;top=right;right=bottom;bottom=tmp;
    }
    void Cubel::rotatesd()
    {
        int tmp=front;front=top;top=back;back=bottom;bottom=tmp;
    }
    void Cubel::rotateupcw() //clockwise
    {
        int tmp=right;right=back;back=left;left=front;front=tmp;
    }
    void Cubel::rotatefdcw()
    {
        int tmp=bottom;bottom=right;right=top;top=left;left=tmp;
    }
    void Cubel::rotatesdcw()
    {
        int tmp=bottom;bottom=back;back=top;top=front;front=tmp;
    }

    void Cubel::draw() // drawing
    {
        glPushMatrix(); // we will scale our cube, so must save model matrix
        glScaled(space,space,space); // just for fun we make space between cubels
        if(chamfers) // draw chamfers
        {
        if(selected) COL(7); // set color
            else COL(0);
        glBegin(GL_TRIANGLES); // draw corner triangles
            NOR(1,1,-1);
            VER(a,a,-1);
            VER(1,a,-a);
            VER(a,1,-a);

            NOR(1,1,1);
            VER(a,a,1);
            VER(1,a,a);
            VER(a,1,a);

            NOR(-1,1,-1);
            VER(-a,a,-1);
            VER(-1,a,-a);
            VER(-a,1,-a);

            NOR(1,-1,-1);
            VER(a,-a,-1);
            VER(1,-a,-a);
            VER(a,-1,-a);
            ///
            NOR(-1,-1,1);
            VER(-a,-a,1);
            VER(-1,-a,a);
            VER(-a,-1,a);

            NOR(1,-1,1);
            VER(a,-a,1);
            VER(1,-a,a);
            VER(a,-1,a);

            NOR(-1,1,1);
            VER(-a,a,1);
            VER(-1,a,a);
            VER(-a,1,a);

            NOR(-1,-1,-1);
            VER(-a,-a,-1);
            VER(-1,-a,-a);
            VER(-a,-1,-a);
        glEnd();
        }
        glBegin(GL_QUADS);
        if(chamfers)
        {
        // chamfer ring 1
            NOR(1,0,-1);
            VER(a,a,-1);
            VER(a,-a,-1);
            VER(1,-a,-a);
            VER(1,a,-a);

            NOR(1,0,1);
            VER(a,a,1);
            VER(a,-a,1);
            VER(1,-a,a);
            VER(1,a,a);

            NOR(-1,0,-1);
            VER(-a,a,-1);
            VER(-a,-a,-1);
            VER(-1,-a,-a);
            VER(-1,a,-a);

            NOR(-1,0,1);
            VER(-a,a,1);
            VER(-a,-a,1);
            VER(-1,-a,a);
            VER(-1,a,a);

        // chamfer ring 2
            NOR(0,1,-1);
            VER(a,a,-1);
            VER(-a,a,-1);
            VER(-a,1,-a);
            VER(a,1,-a);

            NOR(0,1,1);
            VER(a,a,1);
            VER(-a,a,1);
            VER(-a,1,a);
            VER(a,1,a);

            NOR(0,-1,-1);
            VER(a,-a,-1);
            VER(-a,-a,-1);
            VER(-a,-1,-a);
            VER(a,-1,-a);

            NOR(0,-1,1);
            VER(a,-a,1);
            VER(-a,-a,1);
            VER(-a,-1,a);
            VER(a,-1,a);

        // chamfer ring 3
            NOR(-1,1,0);
            VER(-1,a,a);
            VER(-1,a,-a);
            VER(-a,1,-a);
            VER(-a,1,a);

            NOR(1,1,0);
            VER(1,a,a);
            VER(1,a,-a);
            VER(a,1,-a);
            VER(a,1,a);

            NOR(-1,-1,0);
            VER(-1,-a,a);
            VER(-1,-a,-a);
            VER(-a,-1,-a);
            VER(-a,-1,a);

            NOR(1,-1,0);
            VER(1,-a,a);
            VER(1,-a,-a);
            VER(a,-1,-a);
            VER(a,-1,a);
        }
////////////////////////////// faces
            if(faces)
            {
            COL(back);
            NOR(0,0,-1); // back
            VER(a,a,-1);
            VER(a,-a,-1);
            VER(-a,-a,-1);
            VER(-a,a,-1);

            COL(front);
            NOR(0,0,1); // front
            VER(a,a,1);
            VER(a,-a,1);
            VER(-a,-a,1);
            VER(-a,a,1);

            COL(right);
            NOR(1,0,0); //right
            VER(1,a,a);
            VER(1,a,-a);
            VER(1,-a,-a);
            VER(1,-a,a);

            COL(left);
            NOR(-1,0,0); //left
            VER(-1,a,a);
            VER(-1,a,-a);
            VER(-1,-a,-a);
            VER(-1,-a,a);

            COL(top);
            NOR(0,1,0); //up
            VER(-a,1,-a);
            VER(a,1,-a);
            VER(a,1,a);
            VER(-a,1,a);

            COL(bottom);
            NOR(0,-1,0); //down
            VER(-a,-1,-a);
            VER(a,-1,-a);
            VER(a,-1,a);
            VER(-a,-1,a);
            }
        glEnd();
        glPopMatrix(); // restore all changes of position

    }

QString Cubel::tostring()
{
    QString res;
    if(selected) res="+";
    else res="-";
    res+=QString::number(front);
    res+=QString::number(left);
    res+=QString::number(back);
    res+=QString::number(right);
    res+=QString::number(top);
    res+=QString::number(bottom);
    return res;
}

QString Cubel::tofront()
{
    QString res;
    res=QString::number(front);
    return res;
}

QString Cubel::toleft()
{
    QString res;
    res=QString::number(left);
    return res;
}

QString Cubel::toback()
{
    QString res;

    res=QString::number(back);

    return res;
}

QString Cubel::toright()
{
    QString res;

    res=QString::number(right);

    return res;
}

QString Cubel::totop()
{
    QString res;

    res=QString::number(top);

    return res;
}

QString Cubel::tobottom()
{
    QString res;

    res=QString::number(bottom);

    return res;
}

void Cubel::fromstring(QString s)
{
    selected=s[0]=='+';
    front=s[1].digitValue();
    left=s[2].digitValue();
    back=s[3].digitValue();
    right=s[4].digitValue();
    top=s[5].digitValue();
    bottom=s[6].digitValue();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Cubik::reselectbody() // when we change axis or layer cubels must change colors of chamfers
    {
        int i,j,k;
        if(selectax==SD)
        {
            for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                body[i][j][k].selected=(i==selecth);
        }else
        if(selectax==UP)
        {
            for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                body[i][j][k].selected=(j==selecth);
        }else
        if(selectax==FD)
        {
            for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                body[i][j][k].selected=(k==selecth);
        };

    }
    void Cubik::drawuplayer(int h) // we must have funtions for drawing one selected layer normal to every axis
    {
        int i,j;
        glPushMatrix();
        glTranslated(-2,(h-1)*2,-2);

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                body[j][h][i].draw();
                glTranslated(2,0,0);
            }
            glTranslated(-6,0,2);
        }
        glPopMatrix();
    }
    void Cubik::drawsdlayer(int h)
    {
        int i,j;
        glPushMatrix();
        glTranslated((h-1)*2,-2,-2);

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                body[h][i][j].draw();
                glTranslated(0,0,2);
            }
            glTranslated(0,2,-6);
        }
        glPopMatrix();
    }
    void Cubik::drawfdlayer(int h)
    {
        int i,j;
        glPushMatrix();
        glTranslated(-2,-2,(h-1)*2);

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                body[i][j][h].draw();
                glTranslated(0,2,0);
            }
            glTranslated(2,-6,0);
        }
        glPopMatrix();
    }
    void Cubik::rotateupcw() // rotation of selected layer arount vertical axis (y)
    {
        int i,j,h=selecth;
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            body[i][h][j].rotateupcw();

        Cubel tmp=body[2][h][2]; //corner elements
        body[2][h][2]=body[2][h][0];
        body[2][h][0]=body[0][h][0];
        body[0][h][0]=body[0][h][2];
        body[0][h][2]=tmp;

        tmp=body[2][h][1]; // side elements
        body[2][h][1]=body[1][h][0];
        body[1][h][0]=body[0][h][1];
        body[0][h][1]=body[1][h][2];
        body[1][h][2]=tmp;
    }
    void Cubik::rotateup() // rotation of selected layer arount vertical axis (y)
    {
        int i,j,h=selecth;
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            body[i][h][j].rotateup();

        Cubel tmp=body[2][h][2]; //corner elements
        body[2][h][2]=body[0][h][2];
        body[0][h][2]=body[0][h][0];
        body[0][h][0]=body[2][h][0];
        body[2][h][0]=tmp;

        tmp=body[2][h][1]; // side elements
        body[2][h][1]=body[1][h][2];
        body[1][h][2]=body[0][h][1];
        body[0][h][1]=body[1][h][0];
        body[1][h][0]=tmp;
    }
    void Cubik::rotatefd() // around fordward axis (z)
    {
        int i,j,h=selecth;
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            body[i][j][h].rotatefd();

        Cubel tmp=body[2][2][h]; //corner elements
        body[2][2][h]=body[2][0][h];
        body[2][0][h]=body[0][0][h];
        body[0][0][h]=body[0][2][h];
        body[0][2][h]=tmp;

        tmp=body[2][1][h]; // side elements
        body[2][1][h]=body[1][0][h];
        body[1][0][h]=body[0][1][h];
        body[0][1][h]=body[1][2][h];
        body[1][2][h]=tmp;
    }

    void Cubik::rotatefdcw() // around fordward axis (z)
    {
        int i,j,h=selecth;
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            body[i][j][h].rotatefdcw();

        Cubel tmp=body[2][2][h]; //corner elements
        body[2][2][h]=body[0][2][h];
        body[0][2][h]=body[0][0][h];
        body[0][0][h]=body[2][0][h];
        body[2][0][h]=tmp;

        tmp=body[2][1][h]; // side elements
        body[2][1][h]=body[1][2][h];
        body[1][2][h]=body[0][1][h];
        body[0][1][h]=body[1][0][h];
        body[1][0][h]=tmp;
    }
    void Cubik::rotatesd() // around side axis (x)
    {
        int i,j,h=selecth;
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            body[h][i][j].rotatesd();

         Cubel tmp=body[h][2][2]; //corner elements
        body[h][2][2]=body[h][2][0];
        body[h][2][0]=body[h][0][0];
        body[h][0][0]=body[h][0][2];
        body[h][0][2]=tmp;

        tmp=body[h][2][1]; // side elements
        body[h][2][1]=body[h][1][0];
        body[h][1][0]=body[h][0][1];
        body[h][0][1]=body[h][1][2];
        body[h][1][2]=tmp;
    }
    void Cubik::rotatesdcw() // around side axis (x)
    {
        int i,j,h=selecth;
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            body[h][i][j].rotatesdcw();

         Cubel tmp=body[h][2][2]; //corner elements
        body[h][2][2]=body[h][0][2];
        body[h][0][2]=body[h][0][0];
        body[h][0][0]=body[h][2][0];
        body[h][2][0]=tmp;

        tmp=body[h][2][1]; // side elements
        body[h][2][1]=body[h][1][2];
        body[h][1][2]=body[h][0][1];
        body[h][0][1]=body[h][1][0];
        body[h][1][0]=tmp;
    }
//////////////////////////////////////////////////////////////////////////////////////////
    Cubik::Cubik()
    {
        animation=0;
        selecth=1;
        selectax=UP;
        selectangle=0;
        cw=0;
        speed=15;
        reselectbody();
    }
    void Cubik::selax(axis a) // change selected axis
    {
        if(animation) return;
        selectax=a;
        reselectbody();
    }
    void Cubik::selh(int dif) // change selected layer
    {
        if(animation) return;
        selecth+=dif;
        if(selecth>2) selecth=0;
        if(selecth<0) selecth=2;
        reselectbody();
    }
    void Cubik::resetchanges() // assembles cubic into start position
    {
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
            body[i][j][k].reset();
    }
    void Cubik::draw() // draws cube layers along selected axis
    {
        glColor3f(0,0.1,0);
        int i;
        switch(selectax)
        {
            case UP:
                for(i=0;i<3;i++)
                {
                    if(i==selecth) // we can rotate selected layer
                    {
                        glPushMatrix();
                        if(cw){
                            glRotated(selectangle,0,1,0);
                        }
                        else glRotated(-selectangle,0,1,0);
                        drawuplayer(i);
                        glPopMatrix();
                    }
                    else drawuplayer(i);
                }
            break;
            case SD:
                for(i=0;i<3;i++)
                {
                    if(i==selecth)
                    {
                        glPushMatrix();
                        if(cw){glRotated(selectangle,1,0,0);}
                        else {glRotated(-selectangle,1,0,0);}
                        drawsdlayer(i);
                        glPopMatrix();
                    }
                    else drawsdlayer(i);
                }
            break;
            case FD:
                for(i=0;i<3;i++)
                {
                    if(i==selecth)
                    {
                        glPushMatrix();
                        if(cw) {glRotated(selectangle,0,0,1);}
                        else {glRotated(-selectangle,0,0,1);}
                        drawfdlayer(i);
                        glPopMatrix();
                    }
                    else drawfdlayer(i);
                }
            break;
        }
    }
    void Cubik::drawscanning() // draws scanning of text
    {
        glPushMatrix();

        glTranslated(0,0,-2);
        drawfdlayer(0); //front

        glPushMatrix(); //top
        glTranslated(0,6,0);
        glRotated(90,1,0,0);
        drawuplayer(0);
        glPopMatrix();

        glPushMatrix(); //bottom
        glTranslated(0,-6,0);
        glRotated(-90,1,0,0);
        drawuplayer(2);
        glPopMatrix();

        glPushMatrix(); //left
        glTranslated(-6,0,0);
        glRotated(-90,0,1,0);
        drawsdlayer(0);
        glPopMatrix();

        glPushMatrix(); //right
        glTranslated(6,0,0);
        glRotated(90,0,1,0);
        drawsdlayer(2);
        glPopMatrix();

        glPushMatrix(); //back
        glTranslated(12,0,0);
        glRotated(180,0,1,0);
        drawfdlayer(2);
        glPopMatrix();

        glPopMatrix();
    }
    void Cubik::startanimation() // sets initial animation values  (rotate)
    {
        if(animation) return;
        animation=1;
        selectangle=0;
    }
    void Cubik::startanimationcw() // sets initial animation values (counterrotate)
    {
        if(animation) return;
        animation=1;
        selectangle=0;
        cw=1;
    }

    void Cubik::animationframe() // change state of cubic for next frame
    {
        if(!animation) return; // if animation is played;
        //double speed=15;
        selectangle-=speed;   // visual rotatation layer changing angle  /// Edit here to change speed of rotation
      //  qDebug() << "the value of select angle:"<< selectangle;
        if(selectangle<=-90) // if rotation is finished
        {
            animation=0;
         //   qDebug()<< "The animation is clear!";
            selectangle=0;
            if(cw==0){
            switch(selectax)  // perform logical 90 degrees rotation
            {             
                case UP: rotateup();break;
                case FD: rotatefd();break;
                case SD: rotatesd();break;
            }
            }else{
                switch(selectax) {
                case UP: rotateupcw();cw=0;break;
                case FD: rotatefdcw();cw=0;break;
                case SD: rotatesdcw();cw=0;break;
               }
            }
        }
    }
void Cubik::randomize()
{
    int x;
    for(int i=0;i<100;i++)
    {
        x=random()%3;
        x-=1;
        selh(x);
        x=random()%3;
        switch(x)
        {
            case 0: rotateup();break;
            case 1: rotatefd();break;
            case 2: rotatesd();break;
        }
    }
    selh(0);
}
QString Cubik::tostring()
{
    QString res="";
    switch(selectax)
    {
        case UP:res="U"; break;
        case FD:res="F"; break;
        case SD:res="S"; break;
    }
    res+=QString::number(selecth);

    int i,j,k;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    for(k=0;k<3;k++)
    {
        res+=body[i][j][k].tostring();
    }
    return res;
}

QString Cubik::tooutput()
{
    QString res="";

    int i,j,k;

    for(j=2;j>-1;j--)
        for(i=0;i<3;i++)
    //for(k=0;k<3;k++)
    {
        //res+=body[i][j][2].fromstring(s.mid(3+(i*9+j*3+k)*7,1));
        res+=body[i][j][2].tofront();
    }
    res+='\n';
    //for(i=0;i<3;i++)
    for(j=2;j>-1;j--)
    for(k=0;k<3;k++)
    {
        //res+=body[i][j][2].fromstring(s.mid(3+(i*9+j*3+k)*7,1));
        res+=body[0][j][k].toleft();
    }
    res+='\n';

    for(j=2;j>-1;j--)
        for(i=2;i>-1;i--)
    //for(k=0;k<3;k++)
    {
        //res+=body[i][j][2].fromstring(s.mid(3+(i*9+j*3+k)*7,1));
        res+=body[i][j][0].toback();
    }

    res+='\n';
    //for(i=0;i<3;i++)
    for(j=2;j>-1;j--)
    for(k=2;k>-1;k--)
    {
        //res+=body[i][j][2].fromstring(s.mid(3+(i*9+j*3+k)*7,1));
        res+=body[2][j][k].toright();
    }
    res+='\n';

    //for(j=2;j<0;j--)
    for(k=0;k<3;k++)
            for(i=0;i<3;i++)
    {
        //res+=body[i][j][2].fromstring(s.mid(3+(i*9+j*3+k)*7,1));
        res+=body[i][2][k].totop();
    }
    res+='\n';

    //for(j=2;j<0;j--)
    for(k=2;k>-1;k--)
            for(i=0;i<3;i++)
    {
        //res+=body[i][j][2].fromstring(s.mid(3+(i*9+j*3+k)*7,1));
        res+=body[i][0][k].tobottom();
    }


    return res;
}

void Cubik::fromstring(QString s)
{
    switch(s[0].toAscii())
    {
        case 'U':selectax=UP; break;
        case 'F':selectax=FD; break;
        case 'S':selectax=SD; break;
    }
    selecth=s[1].digitValue();
    int i,j,k;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    for(k=0;k<3;k++)
    {
        body[i][j][k].fromstring(s.mid(2+(i*9+j*3+k)*7,7));
    }
}



void Cubik::start8rotation(QString A) // sets initial animation values  (rotate) // A = R,R'...
{

    if(animation) return;

    if(A=="R"||A=="r"){
 //         qDebug()<<"8rotationR";
        selectax=SD;
        selecth=2;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;
    }
    else  if(A=="R'" || A=="r'"){
        selectax=SD;
        selecth=2;

        reselectbody();
        animation=1;
        selectangle=0;
    }

    else  if(A=="U"|| A=="u"){
        selectax=UP;
        selecth=2;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;
    }

    else  if(A=="U'"|| A=="u'"){
        selectax=UP;
        selecth=2;

        reselectbody();
        animation=1;
        selectangle=0;
    }

    else  if(A=="D" || A=="d"){
        selectax=UP;
        selecth=0;

        reselectbody();
        animation=1;
        selectangle=0;

    }

    else  if(A=="D'"|| A=="d'"){
        selectax=UP;
        selecth=0;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;
    }

    else  if(A=="L" || A=="l"){
        selectax=SD;
        selecth=0;

        reselectbody();
        animation=1;
        selectangle=0;
//        qDebug()<< "L is working";

    }

    else  if(A=="L'"||A=="l'"){
        selectax=SD;
        selecth=0;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;
    }

    else  if(A=="F" || A=="f"){
        selectax=FD;
        selecth=2;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;

    }

    else  if(A=="F'"||A=="f'"){
        selectax=FD;
        selecth=2;

        reselectbody();
        animation=1;
        selectangle=0;

    }

    else  if(A=="B" || A=="b"){
        selectax=FD;
        selecth=0;

        reselectbody();
        animation=1;
        selectangle=0;
  //      qDebug()<< "B is working";
    }

    else  if(A=="B'"||A=="b'"){
        selectax=FD;
        selecth=0;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;
    }

    else  if(A=="X2"||A=="x2"){
        selectax=SD;
        selecth=1;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;
    }

    else  if(A=="y2"||A=="Y2"){
        selectax=UP;
        selecth=1;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;
    }
    else  if(A=="Z2"||A=="z2"){
        selectax=FD;
        selecth=1;

        reselectbody();
        animation=1;
        selectangle=0;
        cw=1;
    }

    else  if(A=="X2'"||A=="x2'"){
        selectax=SD;
        selecth=1;

        reselectbody();
        animation=1;
        selectangle=0;

    }

    else  if(A=="y2'"||A=="Y2'"){
        selectax=UP;
        selecth=1;

        reselectbody();
        animation=1;
        selectangle=0;

    }
    else  if(A=="Z2'"||A=="z2'"){
        selectax=FD;
        selecth=1;

        reselectbody();
        animation=1;
        selectangle=0;

    }

}


void Cubik::startfacerotation(QString A) // sets initial animation values  (rotate) // A = R,R'...
{
    //if(animation) return;
    if(A=="X"||A=="x"){

        start8rotation("R");
//        qDebug()<<"STARTFACEROTATION 1";
//        animation=0;
//        selectangle=0;
        QTest::qWait(600);
         start8rotation("X2");

        QTest::qWait(600);
//        qDebug()<< animation;
       start8rotation("L'");
        QTest::qWait(600);

    }
    else if(A=="Y"||A=="y"){

        start8rotation("U");
        QTest::qWait(600);
         start8rotation("y2");
        QTest::qWait(600);
       start8rotation("D'");
        QTest::qWait(600);

    }
    else if(A=="Z"||A=="z"){

        start8rotation("F");
        QTest::qWait(600);
         start8rotation("z2");
        QTest::qWait(600);
       start8rotation("B'");
        QTest::qWait(600);

    }

    if(A=="X'"||A=="x'"){

        start8rotation("R'");

        QTest::qWait(600);
         start8rotation("X2'");

        QTest::qWait(600);

       start8rotation("L");
        QTest::qWait(600);

    }
    else if(A=="Y'"||A=="y'"){

        start8rotation("U'");
        QTest::qWait(600);
         start8rotation("y2'");
        QTest::qWait(600);
       start8rotation("D");
        QTest::qWait(600);

    }
    else if(A=="Z'"||A=="z'"){

        start8rotation("F'");
        QTest::qWait(600);
         start8rotation("z2'");
        QTest::qWait(600);
       start8rotation("B");
        QTest::qWait(600);

    }

    if(A=="X2"||A=="x2"){

        start8rotation("R");

        QTest::qWait(600);
        start8rotation("R");

        QTest::qWait(600);
        start8rotation("X2");

       QTest::qWait(600);
       start8rotation("X2");

      QTest::qWait(600);

       start8rotation("L'");
        QTest::qWait(600);

        start8rotation("L'");
         QTest::qWait(600);

    }
    else if(A=="Y2"||A=="y2"){

        start8rotation("U");
        QTest::qWait(600);
        start8rotation("U");
        QTest::qWait(600);
         start8rotation("y2");
        QTest::qWait(600);
        start8rotation("y2");
       QTest::qWait(600);
       start8rotation("D'");
        QTest::qWait(600);
        start8rotation("D'");
         QTest::qWait(600);

    }
    else if(A=="Z2"||A=="z2"){

        start8rotation("F");
        QTest::qWait(600);
        start8rotation("F");
        QTest::qWait(600);
         start8rotation("z2");
        QTest::qWait(600);
        start8rotation("z2");
       QTest::qWait(600);
       start8rotation("B'");
        QTest::qWait(600);
        start8rotation("B'");
         QTest::qWait(600);

    }



//========================================="Rotate 2 times"========================


    else if(A=="U2"||A=="u2"){

        start8rotation("U");
        QTest::qWait(600);
         start8rotation("U");
        QTest::qWait(600);
    }


    else if(A=="R2"||A=="r2"){

        start8rotation("R");
        QTest::qWait(600);
         start8rotation("R");
        QTest::qWait(600);
    }

    else if(A=="f2"||A=="F2"){

        start8rotation("F");
        QTest::qWait(600);
         start8rotation("F");
        QTest::qWait(600);
    }


    else if(A=="D2"||A=="d2"){

        start8rotation("D");
        QTest::qWait(600);
         start8rotation("D");
        QTest::qWait(600);
    }


    else if(A=="L2"||A=="l2"){

        start8rotation("L");
        QTest::qWait(600);
         start8rotation("L");
        QTest::qWait(600);
    }


    else if(A=="B2"||A=="b2"){

        start8rotation("B");
        QTest::qWait(600);
         start8rotation("B");
        QTest::qWait(600);
    }

}
