#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

#include <QString>

#include <string>



using namespace std;







class cube{
	public:
		int rubik[5][5][5];
		//x=-2+2:back;x=2+2:front
		//y=-2+2:left;y=2+2;right
		//z=-2+2:buttom;z=2+2:up
		//for any valid square on a cube, one, and only one of these three parameters should be +2 or -2
		cube()
		{
			Ini();
		}
		~cube(){}
		void typeIn()
		{
			vector<string> str;
			str.push_back(typeInFace('F'));
			str.push_back(typeInFace('L'));
			str.push_back(typeInFace('B'));
			str.push_back(typeInFace('R'));
			str.push_back(typeInFace('U'));
			str.push_back(typeInFace('D'));
			vector<vector<int> > faceCode=encode(str);
			creaCube(faceCode);
		}

		void readIn(string filename)
		{
			//string filename="cubestate1.txt";
			string templine;
			const char *filenamePoint=filename.c_str();	
			//getline(cin,filename);
			//const char *filenamePoint=filename.data();
			cout<<"readIn: Point 1.0"<<endl;
			ifstream fin(filenamePoint);
			cout<<"readIN: Point 2.0"<<endl;
			if(!fin){
          			cerr<<"!!Cannot open the planetfile. Please try again!"<<endl;
          			exit(EXIT_FAILURE);
				}
			getline(fin,templine);
			vector<string> str;
			while(fin)
			{   // keep read the planetfile
        
				if (templine.empty() || templine.length() == 0 )
				{
					getline(fin,templine);
            //cout<<"blank line11";

				}
				templine=improveFace(templine);
				str.push_back(templine);
				getline(fin,templine);
			}
			fin.close();
			vector<vector<int> > faceCode=encode(str);
			creaCube(faceCode);
		}

		void U()
		{
			rotateLayer('z',1);
			rotateLayer('z',2);
		}
		void Ur()
		{
			U2();
			U();
		}
		void U2()
		{
			U();
			U();
		}
		void R()
		{
			rotateLayer('y',1);
			rotateLayer('y',2);
		}
		void Rr()
		{
			R2();
			R();
		}
		void R2()
		{
			R();
			R();
		}
		void F()
		{
			rotateLayer('x',1);
			rotateLayer('x',2);
		}
		void Fr()
		{
			F2();
			F();
		}
		void F2()
		{
			F();
			F();
		}
		void D()
		{
			D2();
			Dr();
		}
		void Dr()
		{
			rotateLayer('z',-1);
			rotateLayer('z',-2);
		}
		void D2()
		{
			Dr();
			Dr();
		}
		void L()
		{
			L2();
			Lr();
		}
		void Lr()
		{
			rotateLayer('y',-1);
			rotateLayer('y',-2);
		}
		void L2()
		{
			Lr();
			Lr();
		}
		void B()
		{
			B2();
			Br();
		}
		void Br()
		{
			rotateLayer('x',-1);
			rotateLayer('x',-2);
		}
		void B2()
		{
			Br();
			Br();
		}
		void X()
		{
			for(int i=-2;i<3;i++)
				rotateLayer('y',i);
		}
		void Xr()
		{
			X2();
			X();
		}
		void X2()
		{
			X();
			X();
		}
		void Y()
		{
			for(int i=-2;i<3;i++)
				rotateLayer('z',i);
		}
		void Yr()
		{
			Y2();
			Y();
		}
		void Y2()
		{
			Y();
			Y();
		}
		void Z()
		{
			for(int i=-2;i<3;i++)
			{
				rotateLayer('x',i);
			}
		}
		void Zr()
		{
			Z2();
			Z();
		}
		void Z2()
		{
			Z();
			Z();
		}
		void du()
		{
			U();
			E();
		}
		void dur()
		{
			du2();
			du();
		}
		void du2()
		{
			du();
			du();
		}
		void dr()
		{
			R();
			M();
		}
		void drr()
		{
			dr2();
			dr();
		}
		void dr2()
		{
			dr();
			dr();
		}
		void df()
		{
			F();
			S();
		}
		void dfr()
		{
			df2();
			df();
		}
		void df2()
		{
			df();
			df();
		}
		void dd()
		{
			D();
			Er();
		}
		void ddr()
		{
			dd2();
			dd();
		}
		void dd2()
		{
			dd();
			dd();
		}
		void dl()
		{
			L();
			Mr();
		}
		void dlr()
		{
			dl2();
			dl();
		}
		void dl2()
		{
			dl();
			dl();
		}
		void db()
		{
			B();
			Sr();
		}
		void dbr()
		{
			db2();
			db();
		}
		void db2()
		{
			db();
			db();
		}
		void E()
		{
			rotateLayer('z',0);
		}
		void Er()
		{
			E2();
			E();
		}
		void E2()
		{
			E();
			E();
		}
		void M()
		{
			rotateLayer('y',0);
		}
		void Mr()
		{
			M2();
			M();
		}
		void M2()
		{
			M();
			M();
		}
		void S()
		{
			rotateLayer('x',0);
		}
		void Sr()
		{
			S2();
			S();
		}
		void S2()
		{
			S();
			S();
		}
		void Ini()
		{
			int meaningless=10;
			for(int a=0;a<5;a++)
			{
				for(int b=0;b<5;b++)
				{
					for(int c=0;c<5;c++)
					{
						rubik[a][b][c]=meaningless;
						meaningless++;
					}
				}
			}
			IniFace('F');//this color is 1
			IniFace('L');//this color is -2
			IniFace('B');//this color is -1
			IniFace('R');//this color is 2
			IniFace('U');//this color is 3
			IniFace('D');//this color is -3
		}
	private:
		void creaCube(vector<vector<int> > colCode)
		{
			Ini();
			for(int i=0;i<6;i++)
			{
				creaFace(i,colCode[i]);
			}
		}
		void creaFace(int i,vector<int> col)
		{
			int k=0;
			switch(i)
			{
				case 0://front face
				{
					for(int z=1;z>-2;z--)
					{
						for(int y=-1;y<2;y++)
						{
							rubik[2+2][y+2][z+2]=col[k];
							k++;
						}
					}
					break;
				}
				case 1://left face
				{
					for(int z=1;z>-2;z--)
					{
						for(int x=-1;x<2;x++)
						{
							rubik[x+2][-2+2][z+2]=col[k];
							k++;
						}
					}
					break;
				}
				case 2://back face
				{
					for(int z=1;z>-2;z--)
					{
						for(int y=1;y>-2;y--)
						{
							rubik[-2+2][y+2][z+2]=col[k];
							k++;
						}
					}
					break;
				}
				case 3://right face
				{
					for(int z=1;z>-2;z--)
					{
						for(int x=1;x>-2;x--)
						{
							rubik[x+2][2+2][z+2]=col[k];
							k++;
						}
					}
					break;
				}
				case 4://up face
				{
					for(int x=-1;x<2;x++)
					{
						for(int y=-1;y<2;y++)
						{
							rubik[x+2][y+2][2+2]=col[k];
							k++;
						}
					}	
					break;
				}
				case 5://down face
				{
					for(int x=1;x>-2;x--)
					{
						for(int y=-1;y<2;y++)
						{
							rubik[x+2][y+2][-2+2]=col[k];
							k++;
						}
					}
					break;
				}
			}
		}
		vector<vector<int> > encode(vector<string> str)
		{
			vector<int> temp;
			vector<vector<int> > toRet;
			if(str.size()<6)
			{
				cout<<"Error: face number error!"<<endl;
				temp.clear();
				toRet.push_back(temp);
				return toRet;
			}
			
			vector<char> center;
			for(unsigned j=0;j<6;j++)
			{
				center.push_back(str[j].at(4));
				//F=1;L=-2;B=-1;R=2;U=3;D=-3
			}
			
			for(unsigned int i=0;i<6;i++)
			{
				temp.clear();
				int m=0;
				for(unsigned int k=0;k<9;k++)
				{
					m=0;
					if(str[i].at(k)==center[0])
						{temp.push_back(1);m=1;}
					if(str[i].at(k)==center[1])
						{temp.push_back(-2);m=1;}
					if(str[i].at(k)==center[2])
						{temp.push_back(-1);m=1;}
					if(str[i].at(k)==center[3])
						{temp.push_back(2);m=1;}
					if(str[i].at(k)==center[4])
						{temp.push_back(3);m=1;}
					if(str[i].at(k)==center[5])
						{temp.push_back(-3);m=1;}
					if(m==0)
					{
						cout<<"More than 6 colors are typed in!"<<endl;
						cout<<"This color is the 7 th: "<<str[i].at(k)<<endl;
						cout<<"the wrong color is at face:"<<i<<", at number:"<<k<<endl;
						temp.push_back(0);
					}
				}
				toRet.push_back(temp);
			}
			return toRet;
		}
		string improveFace(string str)
		{
			string toRet;
			for(unsigned int i=0;i<str.size();i++)
			{
				if(str[i]>='A'&&str[i]<='Z')
					toRet.push_back(str[i]);
				else
				{
					if(str[i]>='a'&&str[i]<='z')
						toRet.push_back(str[i]-32);
				}
				if(str[i]>='0'&&str[i]<='9')
				{
					toRet.push_back(str[i]);
				}
				
			}
			return toRet;
		}
		string typeInFace(char c)
		{
			string temp="";
			string toRet="";
			if(c=='F'||c=='f')
				cout<<"Please type in the color of the front face:"<<endl;
			if(c=='L'||c=='l')
				cout<<"Please type in the color of the left face:"<<endl;
			if(c=='B'||c=='b')
				cout<<"Please type in the color of the back face:"<<endl;
			if(c=='R'||c=='r')
				cout<<"Please type in the color of the right face:"<<endl;
			if(c=='U'||c=='u')
				cout<<"Please type in the color of the up face:(frontside down)"<<endl;
			if(c=='D'||c=='d')
				cout<<"Please type in the color of the down face:(frontside up)"<<endl;
			getline(cin,temp);
			//cout<<"typeInFace: Point()1.0:temp: "<<temp<<endl;
			for(unsigned int i=0;i<temp.size();i++)
			{
				if(temp[i]>='A'&&temp[i]<='Z')
					toRet.push_back(temp[i]);
				else
				{
					if(temp[i]>='a'&&temp[i]<='z')
						toRet.push_back(temp[i]-32);
				}
			}
			//cout<<"typeInFace: Point()2.0:toRet:"<<toRet<<endl;
			return toRet;
		}
		void IniFace(char face)
		{
			if(face=='F'||face=='f')
			{
				for(int y=-1;y<2;y++)
				{
					for(int z=-1;z<2;z++)
					{
						rubik[2+2][y+2][z+2]=1;
					}
				}
				return;
			}
			if(face=='B'||face=='b')
			{
				for(int y=-1;y<2;y++)
				{
					for(int z=-1;z<2;z++)
					{
						rubik[-2+2][y+2][z+2]=-1;
					}
				}
				return;
			}
			if(face=='L'||face=='l')
			{
				for(int x=-1;x<2;x++)
				{
					for(int z=-1;z<2;z++)
					{
						rubik[x+2][-2+2][z+2]=-2;
					}
				}
				return;
			}
			if(face=='R'||face=='r')
			{
				for(int x=-1;x<2;x++)
				{
					for(int z=-1;z<2;z++)
					{
						rubik[x+2][2+2][z+2]=2;
					}
				}
				return;
			}
			if(face=='U'||face=='u')
			{
				for(int x=-1;x<2;x++)
				{
					for(int y=-1;y<2;y++)
					{
						rubik[x+2][y+2][2+2]=3;
					}
				}
				return;
			}
			if(face=='D'||face=='d')
			{
				for(int x=-1;x<2;x++)
				{
					for(int y=-1;y<2;y++)
					{
						rubik[x+2][y+2][-2+2]=-3;
					}
				}
				return;
			}
		}
		void rotateLayer(char axis,int layer)
			//always use clockwise when looking at anti-axis direction
		{
			vector<vector<int> > rotLay=getLayer(axis,layer);
			vector<vector<int> > *rotLayPoint=&rotLay;
			Clockwise(rotLayPoint);
			insertLayer(axis,layer,rotLayPoint);
			
		}

		vector<vector<int> > getLayer(char axis,int layer)
		{
			vector<vector<int> > toRet;
			vector<int> temp; 
			if(axis=='Z'||axis=='z')
			{

				for(int x=0;x<5;x++)
				{
					temp.clear();
					for(int y=0;y<5;y++)
					{
						temp.push_back(rubik[x][y][layer+2]);
					}
					toRet.push_back(temp);
				}
				return toRet;
			}
			if(axis=='Y'||axis=='y')
			{
				for(int z=2;z>-3;z--)
				{
					temp.clear();
					for(int x=2;x>-3;x--)
					{
						temp.push_back(rubik[x+2][layer+2][z+2]);
					}
					toRet.push_back(temp);
				}
				return toRet;
			}
			if(axis=='X'||axis=='x')
			{
				for(int z=4;z>-1;z--)
				{
					temp.clear();
					for(int y=0;y<5;y++)
					{
						temp.push_back(rubik[layer+2][y][z]);
					}
					toRet.push_back(temp);
				}
				return toRet;
			}
			else
			{
				cout<<"The axis parameter is incorrect!"<<endl;
				temp.push_back(10);
				toRet.push_back(temp);
			}
			return toRet;
		}
		void insertLayer(char axis,int layer,vector<vector<int> > *rotLayPoint)
		{
			if(axis=='Z'||axis=='z')
			{
				for(int x=0;x<5;x++)
				{
					for(int y=0;y<5;y++)
					{
						rubik[x][y][layer+2]=(rotLayPoint->at(x)).at(y);
					}
				}
			}
			if(axis=='Y'||axis=='y')
			{
				for(int z=2;z>-3;z--)
				{
					for(int x=2;x>-3;x--)
						rubik[x+2][layer+2][z+2]=(rotLayPoint->at(2-z)).at(2-x);
				}
			}
			if(axis=='X'||axis=='x')
			{
				for(int z=4;z>-1;z--)
				{
					for(int y=0;y<5;y++)
					{
						rubik[layer+2][y][z]=(rotLayPoint->at(4-z)).at(y);
					}
				}
			}
			
		}

		void Clockwise(vector<vector<int> > *rotLayPoint)
		{
			int temp[5][5];
			for(int a=-2;a<3;a++)
			{
				for(int b=-2;b<3;b++)
				{
					temp[b+2][-a+2]=(rotLayPoint->at(a+2)).at(b+2);
					//make the rotation
				}
			}
			//duplicate the matriix
			for(int x=0;x<5;x++)
			{
				for(int y=0;y<5;y++)
				{
					(rotLayPoint->at(x)).at(y)=temp[x][y];
				}
			}

		}

		void printFace(int face)
		{
			int x=0;int y=0;int z=0;
			switch(face)
			{
				case 0:{x=2;break;}
				case 1:{y=-2;break;}
				case 2:{x=-2;break;}
				case 3:{y=2;break;}
				case 4:{z=2;break;}
				case 5:{z=-2;break;}
			}
			if(x==2)
			{
				cout<<"F:"<<endl;
				for (int k=1;k>-2;k--)
				{
					for(int j=-1;j<2;j++)
					{
						cout<<"|"<<rubik[x+2][j+2][k+2]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			if(x==-2)
			{
				cout<<"B:"<<endl;
				for(int k=1;k>-2;k--)
				{
					for(int j=1;j>-2;j--)
					{
						cout<<"|"<<rubik[x+2][j+2][k+2]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			if(y==-2)
			{
				cout<<"L:"<<endl;
				for(int k=1;k>-2;k--)
				{
					for(int j=-1;j<2;j++)
					{
						cout<<"|"<<rubik[j+2][y+2][k+2]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			if(y==2)
			{
				cout<<"R:"<<endl;
				for(int k=1;k>-2;k--)
				{
					for(int j=1;j>-2;j--)
					{
						cout<<"|"<<rubik[j+2][y+2][k+2]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			if(z==2)
			{
				cout<<"U:(front face downside)"<<endl;
				for(int k=-1;k<2;k++)
				{
					for(int j=-1;j<2;j++)
					{
						cout<<"|"<<rubik[k+2][j+2][z+2]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			if(z==-2)
			{
				cout<<"D:(front face upside)"<<endl;
				for(int k=1;k>-2;k--)
				{
					for(int j=-1;j<2;j++)
					{
						cout<<"|"<<rubik[k+2][j+2][z+2]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
		}
		void doRot(string c)
		{
			if(c=="U"){U();return;}
			if(c=="U'"){Ur();return;}
			if(c=="U2"){U2();return;}
			if(c=="R"){R();return;}
			if(c=="R'"){Rr();return;}
			if(c=="R2"){R2();return;}
			if(c=="F"){F();return;}
			if(c=="F'"){Fr();return;}
			if(c=="F2"){F2();return;}
			if(c=="D"){D();return;}
			if(c=="D'"){Dr();return;}
			if(c=="D2"){D2();return;}
			if(c=="L"){L();return;}
			if(c=="L'"){Lr();return;}
			if(c=="L2"){L2();return;}
			if(c=="B"){B();return;}
			if(c=="B'"){Br();return;}
			if(c=="B2"){B2();return;}
			if(c=="x"){X();return;}
			if(c=="x'"){Xr();return;}
			if(c=="x2"){X2();return;}
			if(c=="y"){Y();return;}
			if(c=="y'"){Yr();return;}
			if(c=="y2"){Y2();return;}
			if(c=="z"){Z();return;}
			if(c=="z'"){Zr();return;}
			if(c=="z2"){Z2();return;}
			if(c=="u"){du();return;}
			if(c=="u'"){dur();return;}
			if(c=="u2"){du2();return;}
			if(c=="r"){dr();return;}
			if(c=="r'"){drr();return;}
			if(c=="r2"){dr2();return;}
			if(c=="f"){df();return;}
			if(c=="f'"){dfr();return;}
			if(c=="f2"){df2();return;}
			if(c=="d"){dd();return;}
			if(c=="d'"){ddr();return;}
			if(c=="d2"){dd2();return;}
			if(c=="l"){dl();return;}
			if(c=="l'"){dlr();return;}
			if(c=="l2"){dl2();return;}
			if(c=="b"){db();return;}
			if(c=="b'"){dbr();return;}
			if(c=="b2"){db2();return;}
			if(c=="E"){E();return;}
			if(c=="E'"){Er();return;}
			if(c=="E2"){E2();return;}
			if(c=="M"){M();return;}
			if(c=="M'"){Mr();return;}
			if(c=="M2"){M2();return;}
			if(c=="S"){S();return;}
			if(c=="S'"){Sr();return;}
			if(c=="S2"){S2();return;}
			else
			{
				  cout<<"An invalid commend:"<<c<<endl;
			}
		}
	public:
		/*
		vector<vector<int> > getFace(char c)
		{
			if(c=='F'||c=='f')

		}
		*/
		void rotate(vector<string> comms)
		{
			for(unsigned int i=0;i<comms.size();i++)
			{
				rotate(comms.at(i));
			}
		}
		void rotate(string comm)
		{
			string c;
			c.clear();
			for(unsigned int i=0;i<comm.size();i++)
			{
				if(comm.at(i)==' ')
				{
					//cout<<"let's do rotation:"<<c<<endl;
					if(c.size()>0)
					{
						doRot(c);
						c.clear();
					}
				}
				else
				{
					c.push_back(comm.at(i));
				}
			}
		}
		void print()
		{
			for (int i=0;i<6;i++)
			{
				switch(i)
				{
					case 0:{cout<<"F:"<<endl;break;}
					case 1:{cout<<"L:"<<endl;break;}
					case 2:{cout<<"B:"<<endl;break;}
					case 3:{cout<<"R:"<<endl;break;}
					case 4:{cout<<"U:"<<endl;break;}
					case 5:{cout<<"D:"<<endl;break;}
				}
				printFace(i);
			}
		}
};




#endif
