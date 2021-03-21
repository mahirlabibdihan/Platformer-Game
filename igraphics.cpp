/*
Normal output screen is in text mode .
We need a screen which is in graphics mode to do graphical work . Opengl does that .
*/
#include "GameManager.h"
#include "color.h"
#include "TilesManager.h"
extern TilesManager tiles;
int iG::iWindowWidth;
int iG::iWindowHeight;
int iG::iWindowX;
int iG::iWindowY;
int iG::iScreenWidth;
int iG::iScreenHeight;
double iG::iClearR;
double iG::iClearG;
double iG::iClearB;

void iG::iInitialize(const char* title)
    {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA) ;
        glutInitWindowSize(iWindowWidth , iWindowHeight ) ;        // Window Size
        glutInitWindowPosition(iWindowX,iWindowY) ;     // Window Position
        glutCreateWindow(title);    // Window Title
        glClearColor( 0.0 , 0.0 , 0.0 , 0.0 ) ;     // Window Background Color
        glMatrixMode( GL_PROJECTION) ;
        glLoadIdentity() ;
        // default window range is (-1,1) in x and (-1,1) in y
        glOrtho(0.0 , iWindowWidth , 0.0 , iWindowHeight , -1.0 , 1.0);    // Window range (0,iWindowWidth) in x and (0,iWindowHeight) in y   
        iClear();

        glutDisplayFunc(displayFF);     // Window Display Callback
        glutKeyboardFunc(keyboardHandler1FF); // Callback when normal key is pressed down
        glutSpecialFunc(keyboardHandler2FF);  // Callback when special key is pressed down
      
        glAlphaFunc(GL_GREATER, 0.0f);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_BLEND);     // Transparent Color
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // Transparent Color
        glLineWidth(2.0);       // Width of drawing lines
    }
