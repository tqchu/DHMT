#include<iostream>

#include<math.h>
#include"camera.h"
#include<GL/glut.h>

using namespace std;

 

typedef float Matrix4 [4][4];

 

Matrix4 theMatrix;

//static GLfloat input[8][3]=

//{

//    {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},

//    {30,30,0},{80,30,0},{80,80,0},{30,80,0}

//

//};

 

static GLfloat input[8][3] ;

float output[8][3];

float tx,ty,tz;

float sx,sy,sz;

float angle;

float Iz; //toa do cua tam chieu nam tren truc OZ

int choice,choiceRot;

 

void inputSquare(){

    float size ;

    cout<<"Enter the length of the cube: ";cin>>size;

    float insertArr [8][3] =

    {

    {0,0,size},{size,0,size},{size,size,size},{0,size,size},

    {0,0,0},{size,0,0},{size,size,0},{0,size,0}

 

    };

   

    for(int i=0;i<8;i++)

    {

        for(int j=0;j<3;j++)

        {

          if(j==2) input[i][j] = insertArr[i][j];

          else input[i][j] = insertArr[i][j];

           

        }

    }

}

 

void printSquare(float a[8][3]){

    cout<<"==========================\n";

    for(int i=0;i<8;i++)

    {

        for(int j=0;j<3;j++)

        {

            cout<<a[i][j] << "\t";

        }

        cout<<"\n";

    }

    cout<<"==========================\n";

}

 

void setIdentityM(Matrix4 m)

{

    for(int i=0;i<4;i++)

    for(int j=0;j<4;j++)   m[i][j]=(i==j);

}
 

void RotateX(float angle) //Parallel to x

{

 angle = angle*3.142/180;

 theMatrix[1][1] = cos(angle);

 theMatrix[1][2] = -sin(angle);

 theMatrix[2][1] = sin(angle);

 theMatrix[2][2] = cos(angle);

}

 

void RotateY(float angle) //parallel to y

{

 angle = angle*3.14/180;

 theMatrix[0][0] = cos(angle);

 theMatrix[0][2] = -sin(angle);

 theMatrix[2][0] = sin(angle);

 theMatrix[2][2] = cos(angle);

}

 

void RotateZ(float angle) //parallel to z

{

 angle = angle*3.14/180;

 theMatrix[0][0] = cos(angle);

 theMatrix[0][1] = sin(angle);

 theMatrix[1][0] = -sin(angle);

 theMatrix[1][1] = cos(angle);

}

 

void multiplyM()

{

//We Don't require 4th row and column in scaling and rotation

//[8][3]=[8][3]*[3][3] //4th not used

for(int i=0;i<8;i++)

{

    for(int j=0;j<3;j++)

    {

        output[i][j]=0;

        for(int k=0;k<3;k++) output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];

    }

}

 

}

void Axes(void)

{

  	glBegin(GL_LINES);
  	
  	glColor3f(1.0, 0.0, 0.0);//RED
  	
  	glVertex3f(-1000.0, 0.0, 0.0);//Ox
  	
  	glVertex3f(1000.0, 0.0, 0.0);
  
	glColor3f(0.0, 1.0, 0.0);//GREEN

  	glVertex3f(0.0, -1000.0, 0.0);//OY

  	glVertex3f(0.0, 1000.0, 0.0);
  	
    glColor3f(0.0, 0.0, 1.0);//BLUE

  	glVertex3f(0.0, 0.0, -1000.0);//OZ

  	glVertex3f(0.0, 0.0, 1000.0);
  	
  	glEnd();

 

//  glBegin(GL_LINES);
//
//  glColor3f(0.0, 1.0, 0.0);//GREEN
//
//  glVertex3f(0.0, -1000000.0, 0.0);//OY
//
//  glVertex3f(0.0, 1000000.0, 0.0);
//
//  glEnd();
//
// 
//
//  glBegin(GL_LINES);
//
//  glColor3f(0.0, 0.0, 1.0);//BLUE
//
//  glVertex3f(0.0, 0.0, -5000000.0);//OZ
//
//  glVertex3f(0.0, 0.0, 5000000.0);
//
//  glEnd();

}

 

void drawInput(float a[8][3])

{

    glBegin(GL_QUADS);

    glColor3f(0.7,0.4,0.5); //behind

    glVertex3fv(a[0]);

    glVertex3fv(a[1]);

    glVertex3fv(a[2]);

    glVertex3fv(a[3]);

 

   glColor3f(0.8,0.2,0.4);  //bottom

   glVertex3fv(a[0]);

   glVertex3fv(a[1]);

   glVertex3fv(a[5]);

   glVertex3fv(a[4]);

 

   glColor3f(0.3,0.6,0.7); //left

   glVertex3fv(a[0]);

   glVertex3fv(a[4]);

   glVertex3fv(a[7]);

   glVertex3fv(a[3]);

 

  glColor3f(0.2,0.8,0.2);  //right

  glVertex3fv(a[1]);

  glVertex3fv(a[2]);

  glVertex3fv(a[6]);

  glVertex3fv(a[5]);

 

 glColor3f(0.7,0.7,0.2); //up

 glVertex3fv(a[2]);

 glVertex3fv(a[3]);

 glVertex3fv(a[7]);

 glVertex3fv(a[6]);

 

 glColor3f(1.0,0.1,0.1);

 glVertex3fv(a[4]);

 glVertex3fv(a[5]);

 glVertex3fv(a[6]);

 glVertex3fv(a[7]);

 

glEnd();


 

}

 

void drawOutput(float a[8][3])

{

    glBegin(GL_QUADS);

    glColor3f(0.0, 0.0, 1.0); //behind

    glVertex3fv(a[0]);

    glVertex3fv(a[1]);

    glVertex3fv(a[2]);

    glVertex3fv(a[3]);

 

   glColor3f(0.0, 0.0, -1.0);  //bottom

   glVertex3fv(a[0]);

   glVertex3fv(a[1]);

   glVertex3fv(a[5]);

   glVertex3fv(a[4]);

 

   glColor3f(0.0, 1.0, 0.0);//left

   glVertex3fv(a[0]);

   glVertex3fv(a[4]);

   glVertex3fv(a[7]);

   glVertex3fv(a[3]);

 

  glColor3f(0.0, -1.0, 0.0);  //right

  glVertex3fv(a[1]);

  glVertex3fv(a[2]);

  glVertex3fv(a[6]);

  glVertex3fv(a[5]);

 

 glColor3f(1.0, 0.0, 0.0);//up

 glVertex3fv(a[2]);

 glVertex3fv(a[3]);

 glVertex3fv(a[7]);

 glVertex3fv(a[6]);

 

 glColor3f(-1.0, 0.0, 0.0);

 glVertex3fv(a[4]);

 glVertex3fv(a[5]);

 glVertex3fv(a[6]);

 glVertex3fv(a[7]);

 

 glEnd();

 

}

 

void init()

{

    glClearColor(1.0,1.0,1.0,0.0); //set backgrond color to black

    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);

    // Set the no. of Co-ordinates along X & Y axes and their gappings

    glEnable(GL_DEPTH_TEST);

     // To Render the surfaces Properly according to their depths

}

 

void display()

{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //top
//    gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
 //side
// gluLookAt(5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//front
//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    Axes();

   

    drawInput(input);

    setIdentityM(theMatrix);
    
    perspective(Iz);
    cout<<"===================\nProjection Matrix\n";
    
    ProjectionMatrix(Iz);

    scale(sx,sy,sz);
	multiplyM();
	cout<<"\nEnter Sx,Sy & Sz: \n";

	cin>>sx>>sy>>sz;
    cout<<"===================\n";

    cout<<"matrix later\n";

    printSquare(output);

    drawOutput(output);

 

    glFlush();

}
Camera cam; // global camera object

 

void myKeyboard(unsigned char key, int x, int y)

{   //use 'F', 'ctrl-F', 'P' and 'ctrl-P' to control the camera

  switch(key)

  {

    // controls for camera

    case 'F': cam.slide(0, 0, 0.2);

    // cout << "The F key is pushed." << '\n';   

              break; // slide camera forward

    case 'F'-64: cam.slide(0,0,-0.2);

    //cout << "The ctrl-F key is pushed." << '\n';   

                 break; //slide camera back

    // add up/down control

    case 'P': cam.pitch(-1.0);

    // cout << "The P key is pushed." << '\n';   

              break;

    case 'P' - 64: cam.pitch( 1.0);

    // cout << "The ctrl-P key is pushed." << '\n';   

                   break;

    // add roll control

    case 'A': cam.roll(-1.0);

    //  cout << "The A key is pushed." << '\n';   

              break;

    case 'A' - 64: cam.roll( 1.0);

    // cout << "The ctrl-A key is pushed." << '\n';   

                   break;

    // add left/right control

    case 'M': cam.yaw(-1.0);

    // cout << "The M key is pushed." << '\n';   

              break;

    case 'M' - 64: cam.yaw( 1.0);

    //  cout << "The ctrl-M key is pushed." << '\n';   

                   break;

  }

  glutPostRedisplay(); // draw it again

}

void myMouse(int button, int state, int x, int y)

{

  switch (button) {

     case GLUT_RIGHT_BUTTON:

        if (state == GLUT_DOWN)

           exit (-1);

        break;

     default:

        break;

  }

}
 

int main(int argc, char** argv)

{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(962,750);

    glutInitWindowPosition(0,0);

    glutCreateWindow("3D TRANSFORMATIONS");


    inputSquare();

    cout<<"================\n";

    cout<<"original matrix\n";

    printSquare(input);

    init(); 
	cout<<"\nEnter Iz(coordinate center of projection on the axis Oz): ";

    cin>>Iz;
	glViewport(0, 0, 480, 480);
	Point3 eye, look;
//
    Vector3 up;
    eye.set(0.0, 0.0, 0.0);

    //eye.set(4, 0, 4);

    look.set(0, 0, 0);

    up.set(0, 0.0, 0);

    cam.set(eye, look, up);       // make the initial camera
    
	cout<<"\nEnter Sx,Sy & Sz: \n";

	cin>>sx>>sy>>sz;
	scale(sx,sy,sz);
	multiplyM();
	
//   	gluLookAt(8.0, 6.0, 12.0,
//   			 0.0, 1.0, 0.0, 
//			 0.0, 1.0, 0.0);               

    cam.setShape(0.0f, 64.0f/58.0f, 0.5f, 50.0f);

    glutKeyboardFunc(myKeyboard);

    glutMouseFunc(myMouse);
    glutDisplayFunc(display);
	
    glutMainLoop();

//   	gluPerspective( 60, 1, 1, 1000 );

return 0;

}//end


