#ifndef __I_GRAPHICS__
#define __I_GRAPHICS__
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <windows.h>
#include <mmsystem.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <tuple>
#include <fstream>
#define PI (acos(-1.0))
using namespace std;
class iG {
protected:
	static int iWindowHeight, iWindowWidth, iScreenHeight, iScreenWidth, iWindowX, iWindowY;
	static double iClearR, iClearG, iClearB;
public:
	static void iDraw();
	static void iKeyboard(unsigned char);
	static void iSpecialKeyboard(unsigned char);

	// Callback functions
	static void displayFF(void)		// Display Callback
	{
		iDraw();
		glutSwapBuffers();
	}
	static void keyboardHandler1FF(unsigned char key, int x, int y)	  // Callback When normal key is pressed down
	{
		iKeyboard(key);
		glutPostRedisplay();
	}
	static void keyboardHandler2FF(int key, int x, int y)	// Callback when special key is pressed down
	{
		iSpecialKeyboard(key);
		glutPostRedisplay();
	}
	// Clears the screen
	static void iClear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glClearColor(iClearR / 255, iClearG / 255, iClearB / 255, 1.0);
		glFlush();
	}

	static int iGetWindowHeight()
	{
		return iWindowHeight;
	}
	static int iGetWindowWidth()
	{
		return iWindowWidth;
	}
	static void iSetWindowHeight(int height)
	{
		iWindowHeight = height;
	}
	static void iSetWindowWidth(int width)
	{
		iWindowWidth = width;
	}
	static int iGetScreenHeight()
	{
		return iScreenHeight;
	}
	static int iGetScreenWidth()
	{
		return iScreenWidth;
	}
	static void iSetScreenHeight(int height)
	{
		iScreenHeight = height;
	}
	static void iSetScreenWidth(int width)
	{
		iScreenWidth = width;
	}
	static void iSetWindowX(double x)
	{
		iWindowX = x;
	}
	static void iSetWindowY(double y)
	{
		iWindowY = y;
	}

	// Draw texts
	static void iText(double x, double y, const char* str, void* font = GLUT_BITMAP_TIMES_ROMAN_24)	//GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_24
	{
		glRasterPos3d(x, y, 0);
		int i;
		for (i = 0; str[i]; i++) {
			glutBitmapCharacter(font, str[i]);
		}
	}

	// Draw Big texts
	static void iBigText(double x, double y, const char* str, void* font = GLUT_STROKE_ROMAN)
	{
		glPushMatrix();
		glTranslatef(x, y, 0);
		int i;
		for (i = 0; str[i]; i++)
			glutStrokeCharacter(font, str[i]); // GLUT_STROKE_ROMAN  , GLUT_STROKE_MONO_ROMAN
		glPopMatrix();
	}
	static void iBigText(double x, double y, string str, void* font = GLUT_STROKE_ROMAN)
	{
		glPushMatrix();
		glTranslatef(x, y, 0);
		int i;
		for (i = 0; str[i]; i++)
			glutStrokeCharacter(font, str[i]); // GLUT_STROKE_ROMAN  , GLUT_STROKE_MONO_ROMAN
		glPopMatrix();
	}

	// Sets color for drawing
	static void iSetColor(double r, double g, double b, double a=1.0)
	{
		double mmx = 255;
		// r,g,b should be 0 to 1
		if (mmx > 0) {
			r /= mmx;
			g /= mmx;
			b /= mmx;
		}
		glColor4f(r, g, b,a);
	}
	// Overloaded
	static void iSetColor(tuple<double, double, double> rgb, double a=1.0)
	{
		double r = get<0>(rgb), g = get<1>(rgb), b = get<2>(rgb);
		double mmx = 255;
		// r,g,b should be 0 to 1
		if (mmx > 0) {
			r /= mmx;
			g /= mmx;
			b /= mmx;
		}
		glColor4f(r, g, b,a);
	}

	// Sets Background color
	static void iSetBGColor(double r, double g, double b)
	{
		iClearR = r;
		iClearG = g;
		iClearB = b;
	}

	// Draw Circle
	static void iCircle(double x, double y, double r, int slices = 100)
	{
		double t, dt=2*PI/slices;
		glBegin(GL_POLYGON);
		for (t = 0; t <= 2 * PI + dt; t += dt)
		{
			glVertex2f(x + r * cos(t), y + r * sin(t));
		}
		glEnd();

		glColor4f(0, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		for (t = 0; t <= 2 * PI + dt; t += dt)
		{
			glVertex2f(x + r * cos(t), y + r * sin(t));
		}
		glEnd();
	}

	// Draws a rectangle
	static void iRectangle(double left, double bottom, double width, double height)
	{
		double x1, y1, x2, y2;
		x1 = left;
		y1 = bottom;
		x2 = x1 + width;
		y2 = y1 + height;

		glBegin(GL_POLYGON);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glVertex2f(x1, y1);
		glEnd();

		glColor4f(0, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glVertex2f(x1, y1);
		glEnd();
	}

	// Opengl window setup 
	static void windowSetup();

	// Initializing opengl Program
	static void iInitialize(const char* title);
};
#endif









