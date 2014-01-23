#ifndef OPPOCROSS_H
#define OPPOCROSS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "solutions.h"
#include "cube.h"

using namespace std;

class Oppocross:public solutions    
{
	private:
		vector<int> translate(char face)
		{
			vector<int> toRet;
			int x=0;int y=0;int z=0;
			if(face=='F'||face=='f'){x=2;}
			if(face=='L'||face=='f'){y=-2;}
			if(face=='B'||face=='b'){x=-2;}
			if(face=='R'||face=='r'){y=2;}
			if(face=='U'||face=='u'){z=2;}
			if(face=='D'||face=='d'){z=-2;}
			toRet.push_back(x);
			toRet.push_back(y);
			toRet.push_back(z);
			return toRet;
		}


		class state{
			public:
			int stateIndex;
			//0:not start yet;
			//1:the cross of the first layer is correct
			//2:first layer is done;
			//3:second layer is done;
			//4:the opposite cross is correct
			//5:the opposite face of the start face is correct;
			//6:everything is correct;
			int startface;
			//1-F,2-L,3-B,4-R,5-U,6-D
			int wrongNumber;
			//in current state, how many small cubes are still need to be correct to reach the next level;
			state():stateIndex(0),startface(1),wrongNumber(0){}
			~state(){}
		};
		
		bool compare(state *sta1,state *sta2)
		{
			if(sta1==NULL)
			{
				//cout<<"compare() point1.0"<<endl;
				return false;
			}
			if(sta1->stateIndex<sta2->stateIndex)
			{
				//cout<<"compare() point2.0"<<endl;
				return false;
			}
			else
			{
				if(sta1->stateIndex==sta2->stateIndex)
				{
					if(sta1->wrongNumber>sta2->wrongNumber)
					{
						//cout<<"compare() point3.0"<<endl;
						return false;
					}
				}
			}
			return true;
		}
	

		state *checkState(cube cub)
		{
			state *sta=NULL;
			state *temp=NULL;
			state *upside=NULL;
			for(int i=0;i<6;i++)//i+1 indicates the face of a cube:1-F,2-L,3-B,4-R,5-U,6-D
			{

				temp=fixFaceCheck(cub,i+1);
				//cout<<"The face number:"<<i+1<<", and the state:"<<temp->stateIndex<<endl;
				if(i==4)
				{
					upside=temp;
				}
				if(temp->stateIndex>=3)
				{
					if(sta!=NULL)
						delete sta;
					return temp;
				}
				if(compare(sta,temp))
				{
					/*
					cout<<"===========checkState() Point1.0:=========="<<endl;
					if(sta==NULL)
						cout<<"no previous highest level!"<<endl;
					else
						cout<<"the previous highest level:"<<sta->stateIndex<<endl;
					cout<<"the current level:"<<temp->stateIndex<<endl;
					*/
					if(i!=4)
						delete temp;
				}
				else
				{
					/*
					cout<<"============checkState() Point2.0:=========="<<endl;
					if(sta==NULL)
						cout<<"no previous highest level!"<<endl;
					else
						cout<<"the previous highest level:"<<sta->stateIndex<<endl;
					cout<<"the current level:"<<temp->stateIndex<<endl;
					*/
					if(sta!=NULL);
						delete sta;
					sta=temp;
				}	
			}
			//cout<<"checkState Point 1.0:stateIndex"<<sta->stateIndex<<endl;
			if(sta->stateIndex==0)
			{
				
				delete sta;
				return upside;

			}
			if(upside!=sta)
				delete upside;
			return sta;
		}

		void switchFace(cube *cubPoint,int face)
		{
			switch(face)
			{
				case 1:break;
				case 2:
				       {
					       cubPoint->Yr();
					       break;
				       }
				case 3:
				       {
					       cubPoint->Y2();
					       break;
				       }
				case 4:
				       {
					       cubPoint->Y();
					       break;
				       }
				case 5:
				       {
					       cubPoint->Xr();
					       break;
				       } 
				case 6:
				       {
					       cubPoint->X();
					       break;
				       }
				default:
				       {
					       cout<<"Wrong parameter for fixFaceCheck():face"<<endl;
				       }
				      
			}
			

		}
		int wrongNo(cube& cub,int level)
		{
			//==========CHECK THE CROSS OF FIRST LAYER=================
			if(level==0)
			{
				int toRet=4;
				int center=cub.rubik[2+2][0+2][0+2];
				if(center==cub.rubik[2+2][1+2][0+2]&&cub.rubik[1+2][2+2][0+2]==cub.rubik[0+2][2+2][0+2])
				{
					//cout<<"wrongNo Point 1.0:toRet:"<<toRet<<endl;
					toRet--;
				}
				if(center==cub.rubik[2+2][-1+2][0+2]&&cub.rubik[1+2][-2+2][0+2]==cub.rubik[0+2][-2+2][0+2])
				{
					//cout<<"wrongNo Point 2.0:toRet:"<<toRet<<endl;
					toRet--;
				}
				if(center==cub.rubik[2+2][0+2][1+2]&&cub.rubik[1+2][0+2][2+2]==cub.rubik[0+2][0+2][2+2])
				{
					//cout<<"wrongNo Point 3.0:toRet:"<<toRet<<endl;
					toRet--;
				}
				if(center==cub.rubik[2+2][0+2][-1+2]&&cub.rubik[1+2][0+2][-2+2]==cub.rubik[0+2][0+2][-2+2])
				{
					//cout<<"wrongNo POint 4.0:toRet:"<<toRet<<endl;
					toRet--;
				}
				return toRet;
			}
			//=========CHECK OTHER CUBES OF THE FIRST LAYER==============
			if(level==1)
			{
				int toRet=4;
				int center=cub.rubik[2+2][0+2][0+2];
				int y=0;
				int z=0;
				for(int i=0;i<4;i++)
				{
					switch(i)
					{
						case 0:
						{
							y=1;
							z=1;
							break;
						}
						case 1:
						{
							y=-1;
							z=1;
							break;
						}
						case 2:
						{
							y=-1;
							z=-1;
							break;
						}
						case 3:
						{
							y=1;
							z=-1;
							break;
						}

					}
					/*
					cout<<"The center color number is "<<center<<endl;
					cout<<"The edge color is "<<cub.rubik[2+2][y+2][z+2]<<endl;
					if(center==cub.rubik[2+2][y+2][z+2])
						cout<<"The 1st requirement is satisfied!"<<endl;
					if(cub.rubik[1+2][2*y+2][z+2]==cub.rubik[0+2][2*y+2][0+2])
						cout<<"The 2nd requirement is satisfied!"<<endl;
					if(cub.rubik[1+2][y+2][2*z+2]==cub.rubik[0+2][0+2][2*z+2])
						cout<<"The 3rd requirement is satisfied!"<<endl;
						*/
					if(center==cub.rubik[2+2][y+2][z+2]&&cub.rubik[1+2][2*y+2][z+2]==cub.rubik[0+2][2*y+2][0+2]&&cub.rubik[1+2][y+2][2*z+2]==cub.rubik[0+2][0+2][2*z+2])
						toRet--;
				}
				//cout<<"the wrong number of corner cubs at first layer:"<<toRet<<endl;
				return toRet;
			}
			//===================CHECK THE SECOND LAYER=====================
			if(level==2)
			{
				int toRet=0;
				int x=0;int y=0;int z=0;
				int x1=0;int y1=0;int z1=0;
				for(int i=0;i<4;i++)
				{
					switch(i)
					{
						case 0:{x=0;y=0;z=2;x1=0;y1=1;z1=2;break;}
						case 1:{x=0;y=2;z=0;x1=0;y1=2;z1=-1;break;}
						case 2:{x=0;y=0;z=-2;x1=0;y1=-1;z1=-2;break;}
						case 3:{x=0;y=-2;z=0;x1=0;y1=-2;z1=1;break;} 
					}
					if(cub.rubik[x+2][y+2][z+2]!=cub.rubik[x1+2][y1+2][z1+2])
					{
						toRet++;
					}
					else
					{
						if(z==z1)
						{
							z=z1/2;
							z1=0;
						}
						else
						{
							z=z1*2;
							z1=z1*2;
						}
						if(y==y1)
						{
							y=y1/2;
							y1=0;
						}
						else
						{
							y=y1*2;
							y1=y1*2;
						}
						if(cub.rubik[x+2][y+2][z+2]!=cub.rubik[x1+2][y1+2][z1+2])
						toRet++;
					}
				}
				//write in the future
				return toRet;
			}

			//=======================FOR THE OPPOSITE CROSS========================//
			if(level==3)
			{
				int toRet=4;
				int z=0;int y=0;
				for(int i=0;i<4;i++)
				{
					switch(i)
					{
						case 0:{z=0;y=-1;break;}
						case 1:{z=0;y=1;break;}
						case 2:{z=-1;y=0;break;}
						case 3:{z=1;y=0;break;}
					}
					//cout<<"the center color:"<<cub.rubik[-2+2][0+2][0+2]<<", the edge color:"<<cub.rubik[-2+2][y+2][z+2];
					if(cub.rubik[-2+2][y+2][z+2]==cub.rubik[-2+2][0+2][0+2])
						toRet--;
				}
				return toRet;
			}


			//============================FOR THE OPPOSITE FACE======================
			
			if(level==4)
			{
				int toRet=9;
				for(int y=-1;y<2;y++)
				{
					for(int z=-1;z<2;z++)
					{
						if(cub.rubik[-2+2][y+2][z+2]==cub.rubik[-2+2][0+2][0+2])
							toRet--;
					}
				}
				return toRet;
			}
			//====================FOR THE LAST LAYER CORNER==============================//
			if(level==5)
			{
				int toRet=4;
				for(int s=0;s<4;s++)
				{
					if(cub.rubik[0+2][0+2][2+2]==cub.rubik[1+2][1+2][2+2]
					&&cub.rubik[2+2][0+2][0+2]==cub.rubik[2+2][0+2][0+2])
					{
						toRet--;
						cub.Yr();
					}
				}
				return toRet;
			}
			//===========================FOR THE LAST LAYER==========================//
			if(level==6)
			{
				int toRet=8;
				int x=0;int y=0;int z=0;
				int temp=0;
				for(int i=0;i<4;i++)
				{
					switch(i)
					{
						case 0:{x=-1;y=0;z=2;break;}
						case 1:{x=-1;y=2;z=0;break;}
						case 2:{x=-1;y=0;z=-2;break;}
						case 3:{x=-1;y=-2;z=0;break;}
					}
					if(y==0)
					{
						for(int k=-1;k<2;k++)
						{
							if(cub.rubik[x+2][k+2][z+2]==cub.rubik[0+2][0+2][z+2])
							{
								if(k==0)
								{
									//cout<<"y=0;toRet-1;toRet="<<toRet<<endl;
									toRet--;
								}
								else
								{
									//cout<<"y=0;toRet-0.5;toRet="<<toRet<<endl;
									if(temp==0)
										temp=1;
									else
									{
										temp=0;
										toRet=toRet-1;
									}
								}
							}
						}
					}
					else
					{
						for(int k=-1;k<2;k++)
						{
							if(cub.rubik[x+2][y+2][k+2]==cub.rubik[0+2][y+2][0+2])
							{
								if(k==0)
								{
									//cout<<"z=0;toRet-1;toRet="<<toRet<<endl;
									toRet--;
								}
								else
								{
									//cout<<"z=0;toRet-0.5;toRet="<<toRet<<endl;
									if(temp==0)
										temp=1;
									else
									{
										temp=0;
										toRet=toRet-1;
									}
								}
							}
						}
					}
				}
				//cout<<"The number of wrong cubes:"<<toRet<<endl;
				return toRet;
			}
			else
			{
				return 1;
			}

		}

		state *fixFaceCheck(cube cub,int face)
		{
			cube * cubPoint=&cub;
			switchFace(cubPoint,face);
			state *staPoint=new state();
			staPoint->startface=face;
			for(int i=0;i<7;i++)
			{
				staPoint->wrongNumber=wrongNo(cub,i);
				//cout<<"fixFaceCheck:Point(1.0): the i is"<<i<<endl;
				//cout<<"the number of wrongs in this check:"<<staPoint->wrongNumber<<endl;
				if(staPoint->wrongNumber!=0)
				{
					//cout<<"the number of i is"<<i<<endl;
					staPoint->stateIndex=i;
					return staPoint;
				}
			}
			staPoint->stateIndex=7;
			return staPoint;

		}
		vector<bool> checkCorrectCube(cube cub,char face,int state)
		{
			vector<bool> toRet;
			//============================MAKE CROSS==================================//
			if(state==0)
			{
				for(int k=0;k<4;k++)
				{
					if(cub.rubik[0+2][0+2][2+2]==cub.rubik[1+2][0+2][-2+2]
					||cub.rubik[2+2][0+2][-1+2]==cub.rubik[0+2][0+2][2+2])
					{
						if(cub.rubik[1+2][0+2][-2+2]==cub.rubik[2+2][0+2][0+2]
						||cub.rubik[2+2][0+2][-1+2]==cub.rubik[2+2][0+2][0+2])
							toRet.push_back(true);
						else
							toRet.push_back(false);
					}
					else
						toRet.push_back(false);
					cub.Yr();
				}

				return toRet;
			}
			//====================FIRST LAYER(CORNER)==============================//
			if(state==1)
			{
				vector<bool> toRet;
				int ux0=0;int uy0=0;int uz0=2;
				int ux1=1;int uy1=1;int uz1=2;
				int lx0=2;int ly0=0;int lz0=0;
				int lx1=2;int ly1=1;int lz1=1;
				int rx0=0;int ry0=2;int rz0=0;
				int rx1=1;int ry1=2;int rz1=1;
				for(int i=0;i<4;i++)
				{
					if(cub.rubik[ux0+2][uy0+2][uz0+2]==cub.rubik[ux1+2][uy1+2][uz1+2]
					&&cub.rubik[lx0+2][ly0+2][lz0+2]==cub.rubik[lx1+2][ly1+2][lz1+2]
					&&cub.rubik[rx0+2][ry0+2][rz0+2]==cub.rubik[rx1+2][ry1+2][rz1+2])
						toRet.push_back(true);
					else
						toRet.push_back(false);
					cub.Yr();
				}
				return toRet;
			}
			//=================SECOND LAYER==================================//
			if(state==2)
			{
				vector<bool> toRet;
				int fx0=2;int fy0=0;int fz0=0;
				int fx1=2;int fy1=1;int fz1=0;
				int rx0=0;int ry0=2;int rz0=0;
				int rx1=1;int ry1=2;int rz1=0;
				for(int i=0;i<4;i++)
				{
					if(cub.rubik[fx0+2][fy0+2][fz0+2]==cub.rubik[fx1+2][fy1+2][fz1+2]
					&&cub.rubik[rx0+2][ry0+2][rz0+2]==cub.rubik[rx1+2][ry1+2][rz1+2])
						toRet.push_back(true);
					else
						toRet.push_back(false);
					cub.Yr();
				}
				return toRet;
			}
			else
			{
				toRet.clear();
			}
			return toRet;
		}

		string makeCross(cube& cub,int startface)
		{
			//cout<<"makeCross Point 1.0: startface:"<<startface<<endl;
			string toRet;
			string *toRetPoint=&toRet;
			//cout<<"Before the face is turned up:"<<endl;
			//cub.print();
			switchFaceUp(&cub,startface,toRetPoint);
			//cout<<"After the face is turned up:"<<endl;
			//cub.print();
			//cout<<"makeCross Point 2.0: toRet: "<<toRet<<endl;
			vector<bool> correctTable=checkCorrectCube(cub,'U',0);
			/*
			int falseNum=0;
			for(unsigned int i=0;i<correctTable.size();i++)
			{
				if(correctTable[i]==true)
					cout<<"true, ";
				else
				{
					cout<<"false, ";
					falseNum++;
				}
			}
			if(falseNum==0)
			{
				cout<<"ALL RIGHT CUBES AT DOWN SIDE:"<<endl;
				cub.print();
			}
			cout<<endl;
			*/
			//cout<<"the size of correctTabe: "<<correctTable.size()<<endl;
			//vector<bool> *cTablePoint=&correctTable;
			//for the correct Table,0-front cube,1-left cube,2-back cube,3-right cube
			//for any element, false- not at the right position, true-right position
			//0 means check the 0th step, the cross cubes
			int i=0;
			while(i<4&&correctTable[i]==true)
			{
				i++;
			}
			switch(i)
			{
				case 0:{break;}
				case 1:{cub.Yr();toRet+="y' ";break;}
				case 2:{cub.Y2();toRet+="y2 ";break;}
				case 3:{cub.Y();toRet+="y ";break;}
				case 4:break;
			}
			int center=cub.rubik[0+2][0+2][2+2];
			int faceColor=cub.rubik[2+2][0+2][0+2];
			string rightCube=findCube(cub, center, faceColor);
			cout<<"rightCube is at:"<<rightCube<<endl;
			if(i<4)
			{
				rightCube=findCube(cub, center, faceColor);
				if(rightCube[0]=='U'||rightCube[1]=='U')
				{
					if(rightCube[0]=='F'||rightCube[1]=='F')
					{
					}
					if(rightCube[0]=='L'||rightCube[1]=='L')
					{
						cub.Ur();
						toRet+="U' ";
					}
					if(rightCube[0]=='B'||rightCube[1]=='B')
					{
						cub.U2();
						toRet+="U2 ";
					}
					if(rightCube[0]=='R'||rightCube[1]=='R')
					{
						cub.U();
						toRet+="U ";
					}
					cub.F2();	
					toRet+="F2 ";
					return toRet;

				}
				else
				{
					if(rightCube[0]=='D'||rightCube[1]=='D')
					{
						if(rightCube[0]=='F'||rightCube[1]=='F')
						{	
						}
						if(rightCube[0]=='L'||rightCube[1]=='L')
						{
							cub.L2();
							cub.Ur();
							cub.F2();
							toRet+="L2 U' F2 ";
							return toRet;
						}
						if(rightCube[0]=='B'||rightCube[1]=='B')
						{
							cub.B2();
							cub.U2();
							cub.F2();
							toRet+="B2 U2 F2 ";
							return toRet;
						}
						if(rightCube[0]=='R'||rightCube[1]=='R')
						{
							cub.R2();
							cub.U();
							cub.F2();
							toRet+="R2 U F2 ";
							return toRet;
						}
					}
					else
					{
						if(rightCube=="LF"||rightCube=="FL")
						{
							cub.F();
							toRet+="F ";
							return toRet;
						}
						if(rightCube=="RF"||rightCube=="FR")
						{
							cub.Fr();
							toRet+="F' ";
							return toRet;
						}
						if(rightCube=="BR"||rightCube=="RB")
						{
							cub.B();
							cub.U2();
							cub.F2();
							cub.Br();
							toRet+="B U2 F2 B' ";
							return toRet;
						}
						if(rightCube=="LB"||rightCube=="BL")
						{
							cub.Br();
							cub.U2();
							cub.F2();
							cub.B();
							toRet+="B' U2 F2 B ";
							return toRet;
						}
					}
				}
			}
			else
			{
				for(int g=0;g<4;g++)
				{
					int m=0;
					rightCube=findCube(cub,cub.rubik[0+2][0+2][2+2],cub.rubik[2+2][0+2][0+2]);
					while(rightCube!="FD"&&rightCube!="DF"&&m<4)
					{
						cub.D();
						toRet+="D ";
						rightCube=findCube(cub,cub.rubik[0+2][0+2][2+2],cub.rubik[2+2][0+2][0+2]);
						m++;
					}
					if(cub.rubik[1+2][0+2][-2+2]==cub.rubik[0+2][0+2][2+2])
					{
						cub.F2();
						toRet+="F2 ";
					}
					else
					{
						if(cub.rubik[2+2][0+2][-1+2]==cub.rubik[0+2][0+2][2+2])
						{
							cub.Dr();
							cub.Lr();
							cub.F();
							cub.L();
							cub.D();
							toRet+="D' L' F L D ";
						}
					}
					cub.Yr();
					toRet+="Y' ";
				}
				return toRet;

			}
			return toRet;

		}
		string findCube(cube cub,int col1,int col2,int col3)
		{
			int x=1;int y=1;int z=1;
			for(int i=0;i<8;i++)
			{
				switch(i)
				{
					case 0:{break;}
					case 1:{cub.Yr();break;}
					case 2:{cub.Y2();break;}
					case 3:{cub.Y();break;}
					case 4:{break;}
					case 5:{cub.Yr();break;}
					case 6:{cub.Y2();break;}
					case 7:{cub.Y();break;}
					default:break;
				}
				if(i<4)
				{
					x=1;y=1;z=1;
					if(cub.rubik[x+2][y+2][z+3]==col1)
					{
						if(cub.rubik[x+3][y+2][z+2]==col2)
						{
							switch(i)
							{
								case 0:return "UFR";
								case 1:return "ULF";
								case 2:return "UBL";
								case 3:return "URB";
							}
						}
					}
					if(cub.rubik[x+3][y+2][z+2]==col1)
					{
						if(cub.rubik[x+2][y+3][z+2]==col2)
						{
							switch(i)
							{
								case 0:return "FRU";
								case 1:return "LFU";
								case 2:return "BLU";
								case 3:return "RBU";
							}
						}
					}
					if(cub.rubik[x+2][y+3][z+2]==col1)
					{
						if(cub.rubik[x+2][y+2][z+3]==col2)
						{
							switch(i)
							{
								case 0:return "RUF";
								case 1:return "FUL";
								case 2:return "LUB";
								case 3:return "BUR";
							}
						}
					}
				}
				else
				{
					x=1;y=1;z=-1;
					if(cub.rubik[x+2][y+2][z+1]==col1)
					{
						if(cub.rubik[x+2][y+3][z+2]==col2)
						{
							switch(i)
							{
								case 4:return "DRF";
								case 5:return "DFL";
								case 6:return "DLB";
								case 7:return "DBR";
							}
						}
					}
					if(cub.rubik[x+2][y+3][z+2]==col1)
					{
						if(cub.rubik[x+3][y+2][z+2]==col2)
						{
							switch(i)
							{
								case 4:return "RFD";
								case 5:return "FLD";
								case 6:return "LBD";
								case 7:return "BRD";
							}
						}
					}
					if(cub.rubik[x+3][y+2][z+2]==col1)
					{
						if(cub.rubik[x+2][y+2][z+1]==col2)
						{
							switch(i)
							{
								case 4:return "FDR";
								case 5:return "LDF";
								case 6:return "BDL";
								case 7:return "RDB";
							}
						}
					}
				}
				switch(i)
				{
					case 0:break;
					case 1:{cub.Y();break;}
					case 2:{cub.Y2();break;}
					case 3:{cub.Yr();break;}
					case 4:{break;}
					case 5:{cub.Y();break;}
					case 6:{cub.Y2();break;}
					case 7:{cub.Yr();break;}
				}

				
			}
			cout<<"Error: correct cube not found!"<<endl;
			return " ";
		}
		//two parameters means that we want to find a cube, and the cube is an edge
		string findCube(cube& cub,int col1,int col2)
		{
			int x1=0;int y1=0;int z1=0;
			int x2=0;int y2=0;int z2=0;
			string str1;
			string str2;
			//cout<<"findCube: Point 1.0: upside color:"<<col1<<"rightside color"<<col2<<endl;
			for(int i=0;i<12;i++)
			{
				switch(i)
				{
					case 0:{x1=1;y1=0;z1=2;x2=2;y2=0;z2=1;str1="UF";str2="FU";break;}
					case 1:{x1=0;y1=-1;z1=2;x2=0;y2=-2;z2=1;str1="UL";str2="LU";break;}
					case 2:{x1=-1;y1=0;z1=2;x2=-2;y2=0;z2=1;str1="UB";str2="BU";break;}
					case 3:{x1=0;y1=1;z1=2;x2=0;y2=2;z2=1;str1="UR";str2="RU";break;}
					case 4:{x1=2;y1=1;z1=0;x2=1;y2=2;z2=0;str1="FR";str2="RF";break;}
					case 5:{x1=2;y1=-1;z1=0;x2=1;y2=-2;z2=0;str1="FL";str2="LF";break;}
					case 6:{x1=-2;y1=1;z1=0;x2=-1;y2=2;z2=0;str1="BR";str2="RB";break;}
					case 7:{x1=-2;y1=-1;z1=0;x2=-1;y2=-2;z2=0;str1="BL";str2="LB";break;}
					case 8:{x1=1;y1=0;z1=-2;x2=2;y2=0;z2=-1;str1="DF";str2="FD";break;}
					case 9:{x1=0;y1=-1;z1=-2;x2=0;y2=-2;z2=-1;str1="DL";str2="LD";break;}
					case 10:{x1=-1;y1=0;z1=-2;x2=-2;y2=0;z2=-1;str1="DB";str2="BD";break;}
					case 11:{x1=0;y1=1;z1=-2;x2=0;y2=2;z2=-1;str1="DR";str2="RD";break;}
				}
				//cout<<"the first face we are reading: "<<x1<<","<<y1<<","<<z1<<endl;
				//cout<<"the color of the first face is :"<<cub.rubik[x1+2][y1+2][z1+2]<<endl;
				//cout<<"the second face we are reading: "<<x2<<","<<y2<<","<<z2<<endl;
				//cout<<"the olor of the second face is: "<<cub.rubik[x2+2][y2+2][z2+2]<<endl;
				if(cub.rubik[x1+2][y1+2][z1+2]==col1&&cub.rubik[x2+2][y2+2][z2+2]==col2)
				{
					/*
					cout<<"Go to 1:"<<endl;
					cout<<"findCube same as up center:"<<x1<<","<<y1<<","<<z1<<endl;
					cout<<"findCube same as right center:"<<x2<<","<<y2<<","<<z2<<endl;
					cout<<str1<<endl;
					*/
					return str1;
				}
				if(cub.rubik[x1+2][y1+2][z1+2]==col2&&cub.rubik[x2+2][y2+2][z2+2]==col1)
				{
					/*
					cout<<"Go to 2:"<<endl;
					cout<<"findCube same as up center:"<<x2<<","<<y2<<","<<z2<<endl;
					cout<<"findCube same as right center:"<<x1<<","<<y1<<","<<z1<<endl;
					*/
					return str2;
				}
			}
			cout<<"Error:This is not a rubik cube, the aimed edge not found!"<<endl;
			str1.clear();
			return str1;
		}

		//as we have a table to record which cube is already at its position, we need to rotate it if the cube rotates.
		void trueTableRot(string sta,vector<bool> *cTablePoint)
		{
			vector<bool> temp;
			if(sta=="Yr")
			{
				for(int i=1;i<4;i++)
				{
					temp.push_back(cTablePoint->at(i));
				}
				temp.push_back(cTablePoint->at(0));
			}
			if(sta=="Y2")
			{
				
				trueTableRot("Yr",cTablePoint);
				trueTableRot("Yr",cTablePoint);
				return;

			}
			if(sta=="Y")
			{
				temp.push_back(cTablePoint->at(3));
				for(int i=0;i<3;i++)
				{
					temp.push_back(cTablePoint->at(i));
				}
			}
			for(int j=0;j<4;j++)
			{
				cTablePoint->at(j)=temp[j];
			}
		}
		
		void switchFaceUp(cube *cubPoint,int startface,string *record)
		{
			switch(startface)
			{
				case 1:{cubPoint->X();(*record)+="x ";break;}
				case 2:{cubPoint->Z();(*record)+="z ";break;}
				case 3:{cubPoint->Xr();(*record)+="x' ";break;}
				case 4:{cubPoint->Zr();(*record)+="z' ";break;}
				case 5:{break;}
				case 6:{cubPoint->X2();(*record)+="x2 ";break;}
			}
		}

		int getFaceCenter(cube& cub,char face, int i)
		{
			//cout<<"the face index is:"<<i<<endl;
			if(face=='U')
			{
				switch(i)
				{
					case 0:return cub.rubik[2+2][0+2][0+2];
					case 1:return cub.rubik[0+2][-2+2][0+2];
					case 2:return cub.rubik[-2+2][0+2][0+2];
					case 3:return cub.rubik[0+2][2+2][0+2];
				}
			}
			return 10;
		}

		string makeFirstLayer(cube& cub, int startface)
		{
			string toRet;
			vector<bool> correctTable=checkCorrectCube(cub,'U',1);
			vector<bool> *cTablePoint=&correctTable;
			//in this table:0-UFR;1-ULF;2-UBL;3-URB
			int i=0;
			while(i<4&&correctTable[i]==true)
			{
				i++;
			}
			if(i==4)
			{
				toRet.clear();
				return toRet;
			}
			//cout<<"mFL Point 1.0: i="<<i<<endl;
			switch(i)
			{
				case 0:{break;}
				case 1:{cub.Yr();trueTableRot("Yr",cTablePoint);toRet+="y' ";break;}
				case 2:{cub.Y2();trueTableRot("Y2",cTablePoint);toRet+="y2 ";break;}
				case 3:{cub.Y();trueTableRot("Y",cTablePoint);toRet+="y ";break;}
				default:break;
			}
			int upColor=cub.rubik[0+2][0+2][2+2];
			int frontColor=cub.rubik[2+2][0+2][0+2];
			int rightColor=cub.rubik[0+2][2+2][0+2];
			//cout<<"BEFORE FINDING THE CUBE:"<<endl;
			//cub.print();
			//cout<<"mFL: point1.0: upColor: "<<upColor<<",frontColor: "<<frontColor<<", rightColor: "<<rightColor<<endl;
			string correctCube=findCube(cub,upColor,frontColor,rightColor);
			if(correctCube.size()<3)
			{
				return toRet;
			}
			int indic=0;
			//string needBack;
			//needBack.clear();
			if(correctCube[0]=='D'&&indic==0)//this is for rotating the cube we want to the corner of FRD so we can easily see it
			{
				if(correctCube[1]=='F')
				{
					cub.D();
					//needBack+="y' ";
					toRet+="D ";
				}
				if(correctCube[1]=='L')
				{
					cub.D2();
					//needBack+="y2 ";
					toRet+="D2 ";
				}
				if(correctCube[1]=='B')
				{
					cub.Dr();
					//needBack+="y ";
					toRet+="D' ";
				}
				cub.Rr();
				cub.D();
				cub.R();
				cub.D2();
				toRet+="R' D R D2 ";
				indic=1;
			}
			if(correctCube[0]=='U'&&indic==0)
			{
				indic=1;
				if(correctCube[1]=='F')
					return toRet;
				if(correctCube[1]=='L')
				{
					cub.Yr();
					//needBack+="y' ";
					toRet+="y' ";
				}
				if(correctCube[1]=='B')
				{
					cub.Y2();
					//needBack+="y2 ";
					toRet+="y2 ";
				}
				if(correctCube[1]=='R')
				{
					cub.Y();
					//needBack+="y ";
					toRet+="y ";
				}
				cub.Rr();
				cub.D();
				cub.R();
				toRet+="R' D R ";
				if(correctCube[1]=='L')
				{
					cub.Y();
					toRet+="y  ";
				}
				if(correctCube[1]=='B')
				{
					cub.Y2();
					toRet+="y2 ";
				}
				if(correctCube[1]=='R')
				{
					cub.Yr();
					toRet+="y' ";
				}
				
			}
			if(correctCube[2]=='U'&&indic==0)
				//this means that the top color of cube we want is at the left side
			{
				if(correctCube[0]=='L')
				{
					cub.Yr();
					toRet+="y' ";
				}
				if(correctCube[0]=='B')
				{
					cub.Y2();
					toRet+="y2 ";
				}
				if(correctCube[0]=='R')
				{
					cub.Y();
					toRet+="y ";
				}
				cub.Rr();
				cub.D();
				cub.R();
				toRet+="R' D R ";
				if(correctCube[0]=='L')
				{
					cub.Y();
					toRet+="y ";
				}
				if(correctCube[0]=='B')
				{
					cub.Y2();
					toRet+="y2 ";
				}
				if(correctCube[0]=='R')
				{
					cub.Yr();
					toRet+="y' ";
				}
			}
			if(correctCube[1]=='U'&&indic==0)
			{
				indic=1;
				if(correctCube[2]=='L')
				{
					cub.Yr();
					toRet+="y' ";
				}
				if(correctCube[2]=='B')
				{
					cub.Y2();
					toRet+="y2 ";
				}
				if(correctCube[2]=='R')
				{
					cub.Y();
					toRet+="y ";
				}
				cub.Rr();
				cub.Dr();
				cub.R();
				cub.D();
				toRet+="R' D' R D ";
				if(correctCube[2]=='L')
				{
					cub.Y();
					toRet+="y ";
				}
				if(correctCube[2]=='B')
				{
					cub.Y2();
					toRet+="y2 ";
				}
				if(correctCube[2]=='R')
				{
					cub.Yr();
					toRet+="y' ";
				}
			}
			correctCube=findCube(cub,upColor,frontColor,rightColor);
			if(correctCube.size()<3)
			{
				cout<<"Error!"<<endl;
				return toRet;
			}
			if(correctCube[1]=='D')
			{
				if(correctCube[0]=='L')
				{
					cub.D();
					toRet+="D ";
				}
				if(correctCube[0]=='B')
				{
					cub.D2();
					toRet+="D2 ";
				}
				if(correctCube[0]=='R')
				{
					cub.Dr();
					toRet+="D' ";
				}
				cub.Dr();
				cub.Rr();
				cub.D();
				cub.R();
				toRet+="D' R' D R ";
			}
			if(correctCube[2]=='D')
			{
				if(correctCube[1]=='L')
				{
					cub.D();
					toRet+="D ";
				}
				if(correctCube[1]=='B')
				{
					cub.D2();
					toRet+="D2 ";
				}
				if(correctCube[1]=='R')
				{
					cub.Dr();
					toRet+="D' ";
				}
				cub.Rr();
				cub.Dr();
				cub.R();
				toRet+="R' D' R ";
			}

			
			return toRet;
		}
		string makeSecondLayer(cube& cub, int startface)
		{
			string toRet;
			string *toRetPoint=&toRet;
			switchFaceUp(&cub,startface,toRetPoint);
			cub.X2();
			if(toRet=="x2 ")
				toRet.clear();
			else
				toRet+="x2 ";
			vector<bool> correctTable=checkCorrectCube(cub,'U',2);
			vector<bool> *cTablePoint=&correctTable;
			int i=0;
			while(i<4&&correctTable[i]==true)
			{
				i++;
			}
			if(i>=4)
			{
				toRet.clear();
				return toRet;
			}
			switch(i)
			{
				case 0:{break;}
				case 1:{cub.Yr();trueTableRot("Yr",cTablePoint);toRet+="y' ";break;}
				case 2:{cub.Y2();trueTableRot("Y2",cTablePoint);toRet+="y2 ";break;}
				case 3:{cub.Y();trueTableRot("Y",cTablePoint);toRet+="y ";break;}
			}
			int frontFace=cub.rubik[2+2][0+2][0+2];
			int rightFace=cub.rubik[0+2][2+2][0+2];
			string correctCube=findCube(cub,frontFace,rightFace);
			if(correctCube[0]!='U'&&correctCube[1]!='U')
			{
				if(correctCube=="LF"||correctCube=="FL")
				{
					cub.Yr();
					toRet+="y' ";
				}
				if(correctCube=="LB"||correctCube=="BL")
				{
					cub.Y2();
					toRet+="y2 ";
				}
				if(correctCube=="BR"||correctCube=="RB")
				{
					cub.Y();
					toRet+="y ";
				}
				cub.Rr();
				cub.Ur();
				cub.Rr();
				cub.Ur();
				cub.Rr();
				cub.U();
				cub.R();
				cub.U();
				cub.R();
				toRet+="R' U' R' U' R' U R U R ";
				if(correctCube=="LF"||correctCube=="FL")
				{
					cub.Y();
					toRet+="y ";
				}
				if(correctCube=="LB"||correctCube=="BL")
				{
					cub.Y2();
					toRet+="y2 ";
				}
				if(correctCube=="BR"||correctCube=="RB")
				{
					cub.Yr();
					toRet+="y' ";
				}
			}
			correctCube=findCube(cub,frontFace,rightFace);
			{				
				if(correctCube[1]=='U')
				{
					if(correctCube[0]=='L')
					{
						cub.Ur();
						toRet+="U' ";
					}
					if(correctCube[0]=='B')
					{
						cub.U2();
						toRet+="U2 ";
					}
					if(correctCube[0]=='R')
					{
						cub.U();
						toRet+="U ";
					}
					cub.Yr();
					cub.R();
					cub.U();
					cub.R();
					cub.U();
					cub.R();
					cub.Ur();
					cub.Rr();
					cub.Ur();
					cub.Rr();
					toRet+="y' R U R U R U' R' U' R' ";
				}
				else
				{
					if(correctCube[1]=='F')
					{
						cub.Ur();
						toRet+="U' ";
					}
					if(correctCube[1]=='L')
					{
						cub.U2();
						toRet+="U2 ";
					}
					if(correctCube[1]=='B')
					{
						cub.U();
						toRet+="U ";
					}
					string temp="R' U' R' U' R' U R U R ";
					cub.rotate(temp);
					toRet+=temp;
				}
			}
			return toRet;
		}

		string makeOppoCross(cube& cub,int startface)
		{
			string toRet;
			string *toRetPoint=&toRet;
			switchFaceUp(&cub,startface,toRetPoint);
			cub.X2();
			if(toRet=="x2 ")
			{
				toRet.clear();
			}
			else
			{
				toRet+="x2 ";
			}
			vector<vector<int> > upFace=getUpFace(cub);
			int center=cub.rubik[0+2][0+2][2+2];
			/*
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<upFace[i][j]<<",";
				}
				cout<<endl;
			}
			*/
			if((upFace[1]).at(0)==center
			&&(upFace[2]).at(1)==center
			&&(upFace[1]).at(2)==center
			&&(upFace[0]).at(1)==center)
			{
				toRet.clear();
				return toRet;
			}
			if((upFace[0]).at(1)==center)
			{
				if((upFace[1]).at(2)==center)
				{
					cub.Yr();
					toRet+="y' ";
				}
				else
				{
					if((upFace[0]).at(1)==center)
					{
						cub.Yr();
						toRet+="y' ";
					}
				}
			}
			string temp="F R U R' U' F' ";
			cub.rotate(temp);
			
			toRet+=temp;
			return toRet;
		}

		vector<vector<int> > getUpFace(cube& cub)
		{
			vector<vector<int> > toRet;
			vector<int> temp;
			for(int x=-1;x<2;x++)
			{
				temp.clear();
				for(int y=-1;y<2;y++)
				{
					temp.push_back(cub.rubik[x+2][y+2][2+2]);
				}
				toRet.push_back(temp);
			}
			return toRet;
		}

		

		string makeOppoFace(cube& cub,int startface)
		{
			string toRet;
			string *toRetPoint=&toRet;
			switchFaceUp(&cub,startface,toRetPoint);
			cub.X2();
			if(toRet=="x2 ")
			{
				toRet.clear();
			}
			else
			{
				toRet+="x2 ";
			}
			int center=cub.rubik[0+2][0+2][2+2];
			vector<vector<int> > T2;
			string temp;
			for(int i=0;i<4;i++)
			{
				T2=topTwoLayer(cub);
				for(int m=0;m<5;m++)
				{
					for(int n=0;n<5;n++)
					{
						cout<<T2[m][n]<<",";
					}
					cout<<endl;
				}
				if(T2[3][3]==center
				&&T2[1][3]!=center
				&&T2[3][1]!=center
				&&T2[1][1]!=center)
				{
					if(T2[0][1]==center)
					{
						//this is the circumstance No.1
						temp="R' U2 R U R' U R ";
						cub.rotate(temp);
						toRet+=temp;
						return toRet;
					}
					else
					{
						temp="R' U2 R U R' U R U2 ";
						cub.rotate(temp);
						toRet+=temp;
						return toRet;
					}
				}
				if(T2[1][1]!=center
				&&T2[1][3]!=center
				&&T2[3][1]!=center
				&&T2[3][3]!=center)
				{
					if(T2[0][1]==center
					&&T2[0][3]==center
					&&T2[4][1]==center
					&&T2[4][3]==center)
					{
						temp="R' U2 R U R' U R ";
						cub.rotate(temp);
						toRet+=temp;
						return toRet;
					}
					if(T2[0][3]==center
					&&T2[1][0]==center
					&&T2[3][0]==center
					&&T2[4][3]==center)
					{
						temp="R' U2 R U R' U R U ";
						cub.rotate(temp);
						toRet+=temp;
						return toRet;
					}
				}
				if(T2[1][1]==center
				&&T2[3][1]==center)
				{
					if(T2[1][4]==center
					&&T2[3][4]==center)
					{
						temp="R' U2 R U R' U R U ";
						cub.rotate(temp);
						toRet+=temp;
						return toRet;
					}
				}
				if(T2[1][1]==center
				&&T2[1][3]==center)
				{
					if(T2[3][0]==center
					&&T2[3][4]==center)
					{
						temp="R' U2 R U R' U R U ";
						cub.rotate(temp);
						toRet+=temp;
						return toRet;
					}
				}
				if(T2[3][1]==center
				&&T2[1][3]==center)
				{
					if(T2[0][1]==center
					&&T2[3][4]==center)
					{
						temp="R' U2 R U R' U R ";
						cub.rotate(temp);
						toRet+=temp;
						return toRet;
					}
				}
				cub.Ur();
				toRet+="U' ";
			}
			//cout<<"Error: solution not found!"<<endl;
			//toRet.clear();
			return toRet;
		}

		
		vector<vector<int> > topTwoLayer(cube& cub)
		{
			vector<vector<int> > toRet;
			vector<int> temp;
			for(int x=-2;x<3;x++)//copy the socond layer(which is the edges of the top layer)
			{
				temp.clear();
				for(int y=-2;y<3;y++)
				{
					temp.push_back(cub.rubik[x+2][y+2][1+2]);
				}
				toRet.push_back(temp);
			}
			for(int a=-1;a<2;a++)
			{
				for(int b=-1;b<2;b++)
				{
					toRet[a+2][b+2]=cub.rubik[a+2][b+2][2+2];
				}
			}
			return toRet;
		}

		string makeLastCorner(cube& cub, int startface)
		{
			string toRet;
			string *toRetPoint=&toRet;
			switchFaceUp(&cub,startface,toRetPoint);
			cub.X2();
			if(toRet=="x2 ")
			{
				toRet.clear();
			}
			else
			{
				toRet+="x2 ";
			}
			//cout<<"mLC Point 1.0: toRet"<<toRet<<endl;
			vector<vector<int> > topEdge=getTopEdge(cub);

			/*
			for(int d=0;d<4;d++)
			{
				for(int e=0;e<3;e++)
				{
					cout<<topEdge[d][e]<<",";
				}
				cout<<endl;
			}
			*/
			int countCorrect=gCCmakeLastCorner(topEdge);
		
			if(countCorrect==0)
			{
				if(topEdge[0][0]==topEdge[2][1]
				&&topEdge[0][2]==topEdge[2][1])
				{
				}
				else
				{
					if(topEdge[0][0]==topEdge[2][2]
					&&topEdge[0][2]==topEdge[2][0])
					{
						cub.U2();
						toRet+="U2 ";
					}
					else
					{
						int j=0;
						while(j<4&&countCorrect>0)
						{
							cub.U();
							toRet+="U ";
							countCorrect=gCCmakeLastCorner(topEdge);
							j++;
						}
						if(countCorrect<=0)
						{
							cout<<"Error: This is not a normal cube!"<<endl;
						}
					}
				}
			}

			if(countCorrect>=2&&countCorrect<4)
			{
				cub.U();
				toRet+="U ";
			}

			if(countCorrect==1)
			{
				if(topEdge[0][0]==topEdge[0][1])
				{
				}
				if(topEdge[1][0]==topEdge[1][1])
				{
					cub.Yr();
					toRet+="y' ";
				}
				if(topEdge[2][0]==topEdge[2][1])
				{
					cub.Y2();
					toRet+="y2 ";
				}
				if(topEdge[3][0]==topEdge[3][1])
				{
					cub.Y();
					toRet+="y ";
				}
			}
			string temp="x' R2 U2 R D R' U2 R D' R x ";
			cub.rotate(temp);
			toRet+=temp;
			return toRet;
			
		}
		int gCCmakeLastCorner(vector<vector<int> > topEdge)
		{
			int countCorrect=0;
			for(int i=0;i<4;i++)
			{
				if(topEdge[i][0]==topEdge[i][1])
				{
					countCorrect++;
				}
			}
			return countCorrect;
		}

		vector<vector<int> > getTopEdge(cube& cub)
		{
			vector<vector<int> > toRet;
			vector<int> temp;
			for(int i=0;i<4;i++)
			{
				temp.clear();
				switch(i)
				{
					case 0:
					{
						temp.push_back(cub.rubik[2+2][-1+2][1+2]);
						temp.push_back(cub.rubik[2+2][0+2][0+2]);
						temp.push_back(cub.rubik[2+2][1+2][1+2]);
						toRet.push_back(temp);
						break;
					}
					case 1:
					{
						temp.push_back(cub.rubik[-1+2][-2+2][1+2]);
						temp.push_back(cub.rubik[0+2][-2+2][0+2]);
						temp.push_back(cub.rubik[1+2][-2+2][1+2]);
						toRet.push_back(temp);
						break;
					}
					case 2:
					{
						temp.push_back(cub.rubik[-2+2][1+2][1+2]);
						temp.push_back(cub.rubik[-2+2][0+2][0+2]);
						temp.push_back(cub.rubik[-2+2][-1+2][1+2]);
						toRet.push_back(temp);
						break;
					}
					case 3:
					{
						temp.push_back(cub.rubik[1+2][2+2][1+2]);
						temp.push_back(cub.rubik[0+2][2+2][0+2]);
						temp.push_back(cub.rubik[-1+2][2+2][1+2]);
						cout<<"cub.rubik[1+2][2+2][1+2]"<<cub.rubik[1+2][2+2][1+2]<<endl;
						toRet.push_back(temp);
						break;
					}
				}
			}
			return toRet;
		}

		string makeFinal(cube& cub,int startface)
		{
			string toRet;
			string *toRetPoint=&toRet;
			switchFaceUp(&cub, startface, toRetPoint);
			cub.X2();
			if(toRet=="x2 ")
			{
				toRet.clear();
			}
			else
			{
				toRet+="x2 ";
			}
			vector<vector<int> > upEdge=gUEmakeFinal(cub);
			cout<<"the size of upedge:"<<upEdge.size()<<endl;
			for(int g=0;g<4;g++)
			{
				for(int k=0;k<2;k++)
				{
					cout<<upEdge[g][k]<<",";
				}
				cout<<endl;
			}
			string temp;
			for(int i=0;i<4;i++)
			{
				if(upEdge[i][0]==upEdge[i][1])
				{
					switch(i)
					{
						case 0:{cub.Y2();toRet+="y2 ";break;}
						case 1:{cub.Y();toRet+="y ";break;}
						case 2:break;
						case 3:{cub.Yr();toRet+="y' ";break;}
					}
					temp="R U' R U R U R U' R' U' R2 ";
					cub.rotate(temp);
					toRet+=temp;
					return toRet;
				}
			}
			if(upEdge[0][0]==upEdge[1][1])
			{
				temp="R U' R U R U R U' R' U' R2 y' ";
				cub.rotate(temp);
				toRet+=temp;
				return toRet;
			}
			else
			{
				if(upEdge[0][0]==upEdge[2][1])
				{
					temp="R U' R U R U R U' R' U' R2 y ";
				}
				else
				{
					temp="y R U' R U R U R U' R' U' R2 y' ";
				}
				cub.rotate(temp);
				toRet+=temp;
				return toRet;
			}
			toRet.clear();
			return toRet;
		}

		vector<vector<int> > gUEmakeFinal(cube& cub)
		{
			vector<vector<int> > toRet;
			vector<int> temp;
			int x=0;int y=0;int z=0;
			for(int i=0;i<4;i++)
			{
				temp.clear();
				switch(i)
				{
					case 0:{x=2;y=0;break;}
					case 1:{x=0;y=-2;break;}
					case 2:{x=-2;y=0;break;}
					case 3:{x=0;y=2;break;}
				}
				temp.push_back(cub.rubik[x+2][y+2][z+3]);
				temp.push_back(cub.rubik[x+2][y+2][z+2]);
				toRet.push_back(temp);
			}
			return toRet;

		}
		/*

		string someSteps(cube& cub, int sf)
		{
			string steps;
			state *staPoint=checkState(cub);
			//cout<<"someSteps point 1.0: stateIndex: "<<staPoint->stateIndex<<endl;
			//cout<<"wrong numbers:"<<staPoint->wrongNumber<<endl;
			//int stepNumber=0;
			
			switch(staPoint->stateIndex)
			{
				case 0:{steps=makeCross(cub,sf);break;}	
				case 1:{steps=makeFirstLayer(cub,staPoint->startface);break;}
				case 2:{steps=makeSecondLayer(cub,staPoint->startface);break;}
				case 3:{steps=makeOppoCross(cub,staPoint->startface);break;}
				case 4:{steps=makeOppoFace(cub,staPoint->startface);break;}
				case 5:{steps=makeLastCorner(cub,staPoint->startface);break;}
				case 6:{steps=makeFinal(cub,staPoint->startface);break;}
			}
			cout<<"The current suggestions:"<<endl;
			cout<<steps<<endl;
						
			//cout<<"the current state:"<<staPoint->stateIndex<<endl;
			//steps=" ";
			delete staPoint;
			return steps;
		}
		*/

	public:
		Oppocross(){}
		~Oppocross(){}
		vector<string> allSteps(cube& cub){
			vector<string> toRet;
			state *staPoint=checkState(cub);
			int count=0;
			//cout<<"allSteps Point 1.0:stateIndex:"<<staPoint->stateIndex<<endl;
			while(staPoint->stateIndex<=6&&count<40)
			{
				toRet.push_back(someSteps(cub));
				staPoint=checkState(cub);
				count++;
			}
			//cout<<"allSteps Point 2.0:stateIndex:"<<staPoint->stateIndex<<endl;
			cout<<"The count is "<<count<<endl;

			printSteps(toRet);

			return toRet;
		}
		void printSteps(vector<string> toPrint)
		{
			for(unsigned int i=0;i<toPrint.size();i++)
			{
				cout<<"("<<toPrint[i]<<")"<<endl;
			}
		}


		string someSteps(cube& cub)
		{
			string steps;
			state *staPoint=checkState(cub);
			//cout<<"someSteps point 1.0: stateIndex: "<<staPoint->stateIndex<<endl;
			//cout<<"wrong numbers:"<<staPoint->wrongNumber<<endl;
			//int stepNumber=0;
			
			switch(staPoint->stateIndex)
			{
				case 0:{steps=makeCross(cub,staPoint->startface);break;}	
				case 1:{steps=makeFirstLayer(cub,staPoint->startface);break;}
				case 2:{steps=makeSecondLayer(cub,staPoint->startface);break;}
				case 3:{steps=makeOppoCross(cub,staPoint->startface);break;}
				case 4:{steps=makeOppoFace(cub,staPoint->startface);break;}
				case 5:{steps=makeLastCorner(cub,staPoint->startface);break;}
				case 6:{steps=makeFinal(cub,staPoint->startface);break;}
			}
			cout<<"The current suggestions:"<<endl;
			cout<<steps<<endl;
						
			//cout<<"the current state:"<<staPoint->stateIndex<<endl;
			//steps=" ";
			delete staPoint;
			return steps;
		}

		string oneRotate(cube& cub){
			string wrong=" ";
			return wrong;
		}

		string hint(cube& cub){
			string wrong=" ";
			return wrong;
		}

		int stepNumber(cube& cub){
			return 0;
		}
};


#endif
