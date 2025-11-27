
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <stdio.h>
#include "GraphicsCore.h"
#include "glPrint.h"



// Reference to OpenGL display list which stores font information
static GLuint		fnt_base = 0;


bool glBuildFont(void)
{
	HFONT		font = NULL;
	HDC			hDC = NULL;

	// Get device context
	hDC = GetDC(NULL);
	if (!hDC)
		return false;

	// Generate and validate display list
	fnt_base = glGenLists(256);
	if (!fnt_base) {
		ReleaseDC(NULL, hDC);
		return false;
	}

	// Create font
	if (!(font = CreateFont(-12,						// Height Of Font
		0,							// Width Of Font
		0,							// Angle Of Escapement
		0,							// Orientation Angle
		FW_BOLD,					// Font Weight
		FALSE,						// Italic
		FALSE,						// Underline
		FALSE,						// Strikeout
		ANSI_CHARSET,				// Character Set Identifier
		OUT_TT_PRECIS,				// Output Precision
		CLIP_DEFAULT_PRECIS,		// Clipping Precision
		ANTIALIASED_QUALITY,		// Output Quality
		FF_DONTCARE | DEFAULT_PITCH,	// Family And Pitch
		L"Courier New"))) {			// Font Name
		glDeleteFont();
		ReleaseDC(NULL, hDC);
		return false;
	}

	SelectObject(hDC, font); // Select current font
	wglUseFontBitmapsA(hDC, 0, 256, fnt_base); // Builds characters

	// Release device context and dispose local resources
	ReleaseDC(NULL, hDC);
	DeleteObject(font);

	return true;
}


void glDeleteFont()
{
	if (fnt_base)
		glDeleteLists(fnt_base, 256);
	fnt_base = 0;
}


// glPrint acts in a similar way to printf
void glPrint(const char *fmt, ...)
{
	char		text[256];
	va_list		ap;

	if (fmt == NULL)
		return;

	// Parse the string for variables
	va_start(ap, fmt);
	vsprintf_s(text, 256, fmt, ap);
	va_end(ap);

	// Render text
	glPushAttrib(GL_LIST_BIT);
	glListBase(fnt_base);
	glCallLists((GLsizei)strlen(text), GL_UNSIGNED_BYTE, text);
	glPopAttrib();
}


