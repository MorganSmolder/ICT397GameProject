#include "RenderModuleStubb.h"

void (*RenderModuleStubb::displayfunc)() = NULL;

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

void RenderModuleStubb::renderArrayTriStrip(std::vector<unsigned> &indicies, std::vector<vec3> &vertices) {
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
}

void RenderModuleStubb::renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec3> & texcoords) {
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glTexCoord2f(texcoords.at(indicies.at(i)).x(), texcoords.at(indicies.at(i)).y());
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();

}

void RenderModuleStubb::init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Shitty Stand In Renderer");

	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void RenderModuleStubb::setUpdateCallBack(void(*callback)()) {
	displayfunc = callback;
	glutDisplayFunc(display);
}

void RenderModuleStubb::setReshapeCallBack() {
	glutReshapeFunc(reshape);
}

void RenderModuleStubb::setKeyCallback() {
	glutKeyboardFunc(keys);
}

void RenderModuleStubb::start() {
	glutMainLoop();
}

void RenderModuleStubb::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	displayfunc();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void RenderModuleStubb::reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90.0f, aspect, 0.1f, 80.0f);
}

void RenderModuleStubb::keys(unsigned char key, int x, int y) {
	switch (key) {
		case 'W':
		case 'w':
			Singleton<MessagingBus>::getInstance()->postMessage(Message("MVF"), Identifiers("", "Camera"));
			break;
		case 'A':
		case 'a':
			Singleton<MessagingBus>::getInstance()->postMessage(Message("MVL"), Identifiers("", "Camera"));
			break;
		case 'D':
		case 'd':
			Singleton<MessagingBus>::getInstance()->postMessage(Message("MVR"), Identifiers("", "Camera"));
			break;
		case 'S':
		case 's':
			Singleton<MessagingBus>::getInstance()->postMessage(Message("MVB"), Identifiers("", "Camera"));
			break;
	}
}