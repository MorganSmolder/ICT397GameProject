#include "RenderModuleStubb.h"

RenderModuleStubb::RenderModuleStubb() {
	id.setName("RM");
	wireframe = false;
}

void RenderModuleStubb::DrawQuad(point tl, point br, float y) {
	glDisable(GL_LIGHTING);
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
	glEnable(GL_LIGHTING);
}

void RenderModuleStubb::DrawQuad(vec3 tl, float widthx, float widthz, float height, vec3 trans){
	glPushMatrix();
	glTranslatef(trans.x(), trans.y(), trans.z());
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(tl.x(), tl.y(), tl.z());
	glTexCoord2f(0, 0);
	glVertex3f(tl.x(), tl.y() + height, tl.z());
	glTexCoord2f(1, 0);
	glVertex3f(tl.x() + widthx, tl.y() + height, tl.z());
	glTexCoord2f(1, 1);
	glVertex3f(tl.x() + widthx, tl.y(), tl.z());

	glTexCoord2f(0, 1);
	glVertex3f(tl.x(), tl.y(), tl.z() + widthz);
	glTexCoord2f(0, 0);
	glVertex3f(tl.x(), tl.y() + height, tl.z() + widthz);
	glTexCoord2f(1, 0);
	glVertex3f(tl.x() + widthx, tl.y() + height, tl.z() + widthz);
	glTexCoord2f(1, 1);
	glVertex3f(tl.x() + widthx, tl.y(), tl.z() + widthz);
	glEnd();

	glPopMatrix();
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

void RenderModuleStubb::renderArrayTriStrip(std::vector<unsigned> &indicies, std::vector<vec3> &vertices, const vec3 & trans) {
	glPushMatrix();
	glTranslatef(trans.x(), trans.y(), trans.z());
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
	glPopMatrix();
}
void RenderModuleStubb::renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec2> & texcoords, const vec3 & trans){
	
	glPushMatrix();
	glTranslatef(trans.x(), trans.y(), trans.z());
	glBegin(GL_TRIANGLES);
	for (unsigned i = 0; i < indicies.size(); i++) {
		if(texcoords.empty() == false) glTexCoord2f(texcoords.at(indicies.at(i)).x(), texcoords.at(indicies.at(i)).y());
		//Temporarily scaled for demo purposes
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
	glPopMatrix();
}

void RenderModuleStubb::renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec3> normals, std::vector<vec2> & texcoords, const vec3 & trans) {
	glPushMatrix();
	glTranslatef(trans.x(), trans.y(), trans.z());
	glBegin(GL_TRIANGLES);
	for (unsigned i = 0; i < indicies.size(); i++) {
		if (texcoords.empty() == false) glTexCoord2f(texcoords.at(indicies.at(i)).x(), texcoords.at(indicies.at(i)).y());
		//Temporarily scaled for demo purposes
		if (normals.empty() == false) glNormal3f(normals.at(indicies.at(i)).x(), normals.at(indicies.at(i)).y(), normals.at(indicies.at(i)).z());
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
	glPopMatrix();
}

void RenderModuleStubb::renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, std::vector<float> lights, const vec3 & trans) {
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(trans.x(), trans.y(), trans.z());
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glColor4ub((GLubyte) lights.at(indicies.at(i)) * 1, (GLubyte) lights.at(indicies.at(i)) * 1, (GLubyte) lights.at(indicies.at(i)) * 1, (GLubyte) 255);
		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, texcoords.at(indicies.at(i)).x(), texcoords.at(indicies.at(i)).y());
		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, texcoords.at(indicies.at(i)).x() * 32, texcoords.at(indicies.at(i)).y() * 32);
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
	glPopMatrix();

	glColor4ub(255, 255, 255, 255); 
	glEnable(GL_LIGHTING);
}

void RenderModuleStubb::renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords) {
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glTexCoord2f(texcoords.at(indicies.at(i)).x(), texcoords.at(indicies.at(i)).y());
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
}

void RenderModuleStubb::renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, const vec3 & trans) {
	glPushMatrix();
	glTranslatef(trans.x(), trans.y(), trans.z());
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned i = 0; i < indicies.size(); i++) {
		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, texcoords.at(indicies.at(i)).x(), texcoords.at(indicies.at(i)).y());
		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, texcoords.at(indicies.at(i)).x()*32, texcoords.at(indicies.at(i)).y()*32);
		glVertex3f(vertices.at(indicies.at(i)).x(), vertices.at(indicies.at(i)).y(), vertices.at(indicies.at(i)).z());
	}
	glEnd();
	glPopMatrix();
}

void RenderModuleStubb::init(int argc, char** argv) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_DEPTH_BITS, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	window = glfwCreateWindow(1280, 720, "Game Engine", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetFramebufferSizeCallback(window, reshape);
	glEnable(GL_TEXTURE_2D);
	
	GLenum err = glewInit();

	if (err != GLEW_OK)
	{ 
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	reshape(window, 1280, 720);
	glClearColor(0.52f, 0.8f, 0.8f, 0.92f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	float ambientLight[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diffuseLight[] = { 1, 1, 1, 1.0f };
	float specularLight[] = { 1, 1, 1, 1.0f };
	float position[] = { 1.0f, 0.5f, 1.0f, 0 };
	
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, ambientLight);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Assign created components to GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void RenderModuleStubb::msgrcvr() {
	MessagingBus* tmp = Singleton<MessagingBus>::getInstance();
	Message tmpm;
	
	while (tmp->hasMessage(id)) {

		tmpm = tmp->getMessage(id);

		if (tmpm.getInstruction() == WIREFRAME) {
			if (wireframe) {
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else {
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			wireframe = !wireframe;
		}
	}
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

void RenderModuleStubb::RenderFacingCamera() {
	glPushMatrix();
	glLoadIdentity();
}

void RenderModuleStubb::StopRenderFacingCamera() {
	glPopMatrix();
}

void RenderModuleStubb::endRenderCycle() {
	glPopMatrix();
	glFlush();
	glfwSwapBuffers(window);
	glfwPollEvents();
	msgrcvr();
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

float RenderModuleStubb::getTimeElapsed() {
	return (float)glfwGetTime();
}


float RenderModuleStubb::getTimeSinceUpdate() {
	
	float currentTime = (float)glfwGetTime();
	float returnTime = (currentTime - timeLastUpdate);
	timeLastUpdate = currentTime;
	return returnTime;
};