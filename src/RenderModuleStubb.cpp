#include "RenderModuleStubb.h"


void RenderModuleStubb::DrawQuad(point tl, point br){
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex2f(tl.x, tl.y);
	glTexCoord2f(0, 0);
	glVertex2f(tl.x, br.y);
	glTexCoord2f(1, 0);
	glVertex2f(br.x, br.y);
	glTexCoord2f(1, 1);
	glVertex2f(br.x, tl.y);
	glEnd();
}

void RenderModuleStubb::storeTexture(const int & texID, unsigned pixelsize, unsigned width, unsigned height, const unsigned char* data){
	glGenTextures(1, (GLuint*) &texID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, (pixelsize == 24) ? GL_RGB : GL_RGBA, width, height, 0, (pixelsize == 24) ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, (const GLvoid*) data);
	glBindTexture(GL_TEXTURE_2D, NULL);
}

void  RenderModuleStubb::deleteTexture(const int & texID){
	glDeleteTextures(1, (GLuint*)&texID);
}

void RenderModuleStubb::bindTexture(const int & texID){
	glBindTexture(GL_TEXTURE_2D, texID);
}