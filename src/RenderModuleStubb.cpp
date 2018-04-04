#include "RenderModuleStubb.h"

RenderModuleStubb::RenderModuleStubb() {
}

void RenderModuleStubb::DrawQuad(point tl, point br, float y){
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(tl.x, tl.y, y);
	glTexCoord2f(0, 0);
	glVertex3f(tl.x, br.y, y);
	glTexCoord2f(1, 0);
	glVertex3f(br.x, br.y, y);
	glTexCoord2f(1, 1);
	glVertex3f(br.x, tl.y, y);
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

void RenderModuleStubb::bindMultiTexture(const int & texIDcolor, const int & texIDdetail) {
	glDisable(GL_BLEND);

	glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, texIDcolor);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glActiveTextureARB(GL_TEXTURE1_ARB);
	glBindTexture(GL_TEXTURE_2D, texIDdetail);
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvi(GL_TEXTURE_ENV, GL_RGB_SCALE_ARB, 2);
}

void RenderModuleStubb::bindTexture(const int & texID){
	glBindTexture(GL_TEXTURE_2D, texID);
}

void RenderModuleStubb::disableMultiTexture() {
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void RenderModuleStubb::renderArrayTriStrip(std::vector<unsigned> &indicies, std::vector<vec3> &vertices) {
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
}
//renderarraytri
//glBegin(GL_TRIANGLES
void RenderModuleStubb::renderArrayTri(std::vector<unsigned> &indicies, std::vector<vec3> &vertices) {
	
	glBegin(GL_TRIANGLES);

	for (unsigned i = 0; i < indicies.size(); i++) {
		glVertex3f(vertices[indicies[i]].x(), vertices[indicies[i]].y(), vertices[indicies[i]].z());
	}
	glEnd();

}


void RenderModuleStubb::renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords) {
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glTexCoord2f(texcoords.at(indicies.at(i)).x(), texcoords.at(indicies.at(i)).y());
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
}

void RenderModuleStubb::renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords) {
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, texcoords.at(indicies.at(i)).x(), texcoords.at(indicies.at(i)).y());
		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, texcoords.at(indicies.at(i)).x()*32, texcoords.at(indicies.at(i)).y()*32);
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
}

void RenderModuleStubb::init(int argc, char** argv) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_DEPTH_BITS, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	window = glfwCreateWindow(1280, 720, "Shitty Render Standin", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetFramebufferSizeCallback(window, reshape);
	glEnable(GL_TEXTURE_2D);
	
	GLenum err = glewInit();

	if (err != GLEW_OK)
	{ 
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	if (glewIsSupported("GL_ARB_multitexture"))
	{
		std::cout << "multtex yes" << std::endl;
	}
	else {
		std::cout << "bad" << std::endl;
	}

	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		
	}

	reshape(window, 1280, 720);
	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void RenderModuleStubb::setKeyCallback() {
	glfwSetKeyCallback(window, keys);
}

void RenderModuleStubb::startRenderCycle() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(campos.x(), campos.y(), campos.z(),
		camlook.x(), camlook.y(), camlook.z(),
		0.0f, 1.0f, 0.0f);
	glPushMatrix();
}

void RenderModuleStubb::endRenderCycle() {
	glPopMatrix();
	glFlush();
	glfwSwapBuffers(window);
	glfwPollEvents();
}


void RenderModuleStubb::reshape(GLFWwindow* window, int width, int height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0f, aspect, 1, 10000);
	glMatrixMode(GL_MODELVIEW);
}

void RenderModuleStubb::callLookAt(vec3 r1, vec3 r2, vec3 r3) {
	campos = r1;
	camlook = r2;

}

void RenderModuleStubb::keys(GLFWwindow* window, int key, int scancode, int action, int mods) {
	switch (key) {
		case 'W':
		case 'w':
			if(action == GLFW_PRESS || action == GLFW_REPEAT)
			Singleton<MessagingBus>::getInstance()->postMessage(Message("MVF"), Identifiers("", "Camera"));
			else
			Singleton<MessagingBus>::getInstance()->postMessage(Message("SFB"), Identifiers("", "Camera"));
			break;
		case 'A':
		case 'a':
			if (action == GLFW_PRESS || action == GLFW_REPEAT)
			Singleton<MessagingBus>::getInstance()->postMessage(Message("MVL"), Identifiers("", "Camera"));
			else
			Singleton<MessagingBus>::getInstance()->postMessage(Message("SLR"), Identifiers("", "Camera"));
			break;
		case 'D':
		case 'd':
			if (action == GLFW_PRESS || action == GLFW_REPEAT)
			Singleton<MessagingBus>::getInstance()->postMessage(Message("MVR"), Identifiers("", "Camera"));
			else
			Singleton<MessagingBus>::getInstance()->postMessage(Message("SLR"), Identifiers("", "Camera"));
			break;
		case 'S':
		case 's':
			if (action == GLFW_PRESS || action == GLFW_REPEAT)
			Singleton<MessagingBus>::getInstance()->postMessage(Message("MVB"), Identifiers("", "Camera"));
			else
			Singleton<MessagingBus>::getInstance()->postMessage(Message("SFB"), Identifiers("", "Camera"));
			break;
		case 'Q':
		case 'q':
			if (action == GLFW_PRESS || action == GLFW_REPEAT)
			Singleton<MessagingBus>::getInstance()->postMessage(Message("LD"), Identifiers("", "Camera"));
			else
			Singleton<MessagingBus>::getInstance()->postMessage(Message("SUD"), Identifiers("", "Camera"));
			break;
		case 'E':
		case 'e':
			if (action == GLFW_PRESS || action == GLFW_REPEAT)
			Singleton<MessagingBus>::getInstance()->postMessage(Message("LU"), Identifiers("", "Camera"));
			else
			Singleton<MessagingBus>::getInstance()->postMessage(Message("SUD"), Identifiers("", "Camera"));
			break;
	}
}
