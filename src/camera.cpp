
#include "Camera.h"

#include <math.h>

//--------------------------------------------------------------------------------------
// Set initial values
//--------------------------------------------------------------------------------------
Camera::Camera(Identifiers & id, vec3 pos, ResourceList & list) : GameObject(id, pos, list)
{
	
	//m_rotateSpeed = 0.1f;
	moveSpeed = 0.4f;
	/*
	ResetXYZ();

	m_deltaMoveFB = 0;
	m_deltaMoveLR = 0;
	m_deltaMoveUD = 0;

	m_rotateAngleLR = 0.0;
	m_rotateAngleUD = 0.0;
	m_deltaAngleLR = 0.0;
	m_deltaAngleUD = 0.0;
	*/

	fov = 50.0f;
	nearPlane = 0.01f;
	farPlane = 100.0f;
	aspectRatio = (4.0f / 3.0f);
	position.x = 0.0f;
	position.y = 5.0f;
	position.z = 1.0f;
	horizontalAngle = 0.0f;
	verticalAngle = 0.0f;

	callGLLookAt();
}

//--------------------------------------------------------------------------------------
// Reset camera values
//--------------------------------------------------------------------------------------
/*
void Camera::ResetXYZ()
{
	
	m_lookX = 0.0f;
	m_lookY = 0.0f;
	m_lookZ = -1.0f;
	
	m_lookXX = 1.0f;
	m_lookYY = 1.0f;
	m_lookZZ = 0.0f;
}

*/

void Camera::update(float time) {
	msgrcvr();

	/////////pos.sy(pos.y() + 10);

	MessagingBus* tmp = Singleton<MessagingBus>::getInstance();
	Message tmpm;

	bool in = false;

	while (tmp->hasMessage(id)) {
		in = true;
		tmpm = tmp->getMessage(id);

		if (tmpm.getInstruction() == "MVF") {
			std::cout << "MVF" << std::endl;
			glm::vec3 tmp = (time * moveSpeed * GetCamZ());
			MovePosition(tmp);
			pos.sx(position.x);
			pos.sy(position.y);
			pos.sz(position.z);
			callGLLookAt();
		}
		else
		if (tmpm.getInstruction() == "MVB") {
			std::cout << "MVB" << std::endl;
			glm::vec3 tmp = (time * moveSpeed * -GetCamZ());
			MovePosition(tmp);
			pos.sx(position.x);
			pos.sy(position.y);
			pos.sz(position.z);
			callGLLookAt();
		}
		else
		if (tmpm.getInstruction() == "MVR") {
			std::cout << "MVR" << std::endl;
			MovePosition(time * moveSpeed * GetCamX());
			pos.sx(position.x);
			pos.sy(position.y);
			pos.sz(position.z);
			callGLLookAt();
		}
		else
		if (tmpm.getInstruction() == "MVL") {
			//std::cout << "MVL" << std::endl;
			MovePosition(time * moveSpeed * -GetCamX());
			pos.sx(position.x);
			pos.sy(position.y);
			pos.sz(position.z);
			callGLLookAt();
		}
		else
		if (tmpm.getInstruction() == "SFB") {
			std::cout << "SFB" << std::endl;
			//DirectionFB(0);
		}
		else
		if (tmpm.getInstruction() == "SLR") {
			std::cout << "SLR" << std::endl;
			//DirectionRotateLR(0);
		}
		else
		if (tmpm.getInstruction() == "LD") {
			std::cout << "LD" << std::endl;
			MovePosition(time * moveSpeed * -glm::vec3(0, 1, 0));
			pos.sx(position.x);
			pos.sy(position.y);
			pos.sz(position.z);
			callGLLookAt();
		}
		else
		if (tmpm.getInstruction() == "LU") {
			std::cout << "LU" << std::endl;
			MovePosition(time * moveSpeed * glm::vec3(0, 1, 0));
			pos.sx(position.x);
			pos.sy(position.y);
			pos.sz(position.z);
			callGLLookAt();
		}
		else
		if (tmpm.getInstruction() == "SUD") {
			std::cout << "SUD" << std::endl;
			//DirectionLookUD(0);
			callGLLookAt();
		}

		std::cout << pos.x() << " " << pos.y() << " " << pos.z() << std::endl;
	}
	//CorrectAngleBoundaries();

	callGLLookAt();
	//
}




void Camera::render() {

}
/*
//--------------------------------------------------------------------------------------
//  Determine direction
//--------------------------------------------------------------------------------------
void Camera::DirectionFB(int const & tempMove)
{
	m_deltaMoveFB = tempMove;
}
//--------------------------------------------------------------------------------------
void Camera::DirectionLR(int const & tempMove)
{
	m_deltaMoveLR = tempMove;
}
//--------------------------------------------------------------------------------------
// Not used but allows up and don movement
void Camera::DirectionUD(int const & tempMove)
{
	m_deltaMoveUD = tempMove;
}

//--------------------------------------------------------------------------------------
void Camera::DirectionRotateLR(GLdouble const & tempMove)
{
	m_deltaAngleLR = tempMove * m_rotateSpeed;
}

//--------------------------------------------------------------------------------------

void Camera::DirectionLookUD(int const & tempMove)
{
	m_deltaAngleUD = tempMove * m_rotateSpeed;
}
*/

//--------------------------------------------------------------------------------------
// Is ok to move camera backwards and forwards
//--------------------------------------------------------------------------------------
/*
bool Camera::MoveFBOK()
{
	bool tempReturn;
	if (m_deltaMoveFB < 0 || m_deltaMoveFB > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}
*/
//--------------------------------------------------------------------------------------
// Is ok to move camera sideways
//--------------------------------------------------------------------------------------
/*
bool Camera::MoveLROK()
{
	bool tempReturn;
	if (m_deltaMoveLR < 0 || m_deltaMoveLR > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}
*/
//--------------------------------------------------------------------------------------
// Is ok to move camera up and down (not used)
//--------------------------------------------------------------------------------------
/*
bool Camera::MoveUDOK()
{
	bool tempReturn;
	if (m_deltaMoveUD < 0 || m_deltaMoveUD > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}
*/
//--------------------------------------------------------------------------------------
// Is ok to rotate sideways
//--------------------------------------------------------------------------------------
/*
bool Camera::RotateLROK()
{
	bool tempReturn;
	if ((m_deltaAngleLR/m_rotateSpeed) < 0 || (m_deltaAngleLR/m_rotateSpeed) > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}
*/
//--------------------------------------------------------------------------------------
// Is ok to rotate up and down
//--------------------------------------------------------------------------------------
/*
bool Camera::LookUDOK()
{
	bool tempReturn;
	if ((m_deltaAngleUD/m_rotateSpeed) < 0 || (m_deltaAngleUD/m_rotateSpeed) > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}
*/
//--------------------------------------------------------------------------------------
// Move camera backwards and forwards
//--------------------------------------------------------------------------------------
/*
void Camera::MoveFB()
{
	// set movement step
	GLdouble moveZ = (m_deltaMoveFB * (m_lookZ) * m_moveSpeed);
	GLdouble moveX = (m_deltaMoveFB * (m_lookX) * m_moveSpeed);

	// increment position
	pos.sx(pos.x() + moveX);
	pos.sz(pos.z() + moveZ);

	// redisplay
	callGLLookAt();
}
*/
//--------------------------------------------------------------------------------------
// Move camera left and right (sideways)
//--------------------------------------------------------------------------------------
/*void Camera::MoveLR()
{

	// set movement step
	GLdouble moveZ = (m_deltaMoveLR * (m_lookZZ) * m_moveSpeed);
	GLdouble moveX = (m_deltaMoveLR * (m_lookXX) * m_moveSpeed);
	
	pos.sx(pos.x() + moveX);
	pos.sz(pos.z() + moveZ);

	callGLLookAt();

}
*/
//----------------------------------------------------------------------------------------
// Moves camera up and down (NOT USED)
//----------------------------------------------------------------------------------------
//void Camera::MoveUD()
/*
{
	pos.sy(m_deltaMoveUD * (m_lookYY)* m_moveSpeed);
	callGLLookAt();

}
*/
//----------------------------------------------------------------------------------------
// Rotates camera left and right
//----------------------------------------------------------------------------------------
/*
void Camera::RotateLR()
{
	m_rotateAngleLR += m_deltaAngleLR;
	m_lookX = sin(m_rotateAngleLR);
	m_lookZ = -cos(m_rotateAngleLR);
	m_lookXX = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookZZ = -cos(m_rotateAngleLR + (float) PI/2.0);
	callGLLookAt();
}
*/
//----------------------------------------------------------------------------------------
//  Rotates camera up and down
//----------------------------------------------------------------------------------------
/*

void Camera::LookUD()
{
	m_rotateAngleUD += m_deltaAngleUD;
	m_lookY = sin(m_rotateAngleUD);
	callGLLookAt();
}
*/
//----------------------------------------------------------------------------------------
// Positions camera at co-ordinates of parameters
//----------------------------------------------------------------------------------------

/*
void Camera::Position (GLdouble const & tempX, GLdouble const & tempY,
	GLdouble const & tempZ, GLdouble const & tempAngle, GLdouble const & tempAnglUD)
{
	ResetXYZ();
	
	pos.sx(tempX);
	pos.sy(tempY);
	pos.sy(tempZ);

	// rotate to correct angle
	m_rotateAngleLR = tempAngle * (PI / 180);
	if (tempAnglUD != 0){
		m_rotateAngleUD = tempAngle * (PI / 180);
	}
	m_lookX = sin(m_rotateAngleLR);
	m_lookZ = -cos(m_rotateAngleLR);
	//m_lookY = sin(m_rotateAngleUD);
	m_lookXX = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookZZ = -cos(m_rotateAngleLR + (float) PI/2.0);
	m_rotateAngleUD = 0.0;
	m_deltaAngleUD = 0.0;

	// redislay
	callGLLookAt();
}

//----------------------------------------------------------------------------------------
// Check ok to move
//----------------------------------------------------------------------------------------
/*void Camera::CheckCamera()
{
	if (MoveFBOK()) MoveFB();
	if (MoveLROK()) MoveLR();
	if (MoveUDOK()) MoveUD();
	if (RotateLROK()) RotateLR();
	if (LookUDOK()) LookUD();
}
*/

//----------------------------------------------------------------------------------------
//  Redisplay new camera view
//----------------------------------------------------------------------------------------
void Camera::callGLLookAt()
{
	glm::vec3 lookAtvec = GetCamZ();
	glm::vec3 camUpVec = GetCamY();
	
	//Singleton<RenderModuleStubb>::getInstance()->callLookAt(vec3(pos.x(), pos.y(), pos.z()), vec3(pos.x() + m_lookX, pos.y() + m_lookY, pos.z() + m_lookZ), vec3(0,1,0));
	//glm::vec3 lookAtvec = GetCamZ();
	Singleton<RenderModuleStubb>::getInstance()->callLookAt(vec3(pos.x(), pos.y(), pos.z()), vec3(pos.x() + lookAtvec.x, pos.y() + lookAtvec.y , pos.z() + lookAtvec.z ), vec3(camUpVec.x, camUpVec.y, camUpVec.z));


	//glLoadIdentity();
	//gluLookAt(pos.x(), pos.y(), pos.z(), 
	//	pos.x() + m_lookX, pos.y() + m_lookY, pos.z() + m_lookZ,
	//		  0.0f, 1.0f, 0.0f);

}

void Camera::SetFov(float fov) {
	assert(fov > 0.0f && fov < 180.0f);
	fov = fov;
}

void Camera::SetFrustrumNearFar(float nearPlane, float farPlane) {
	assert(nearPlane > 0.0f);
	assert(farPlane > nearPlane);
	nearPlane = nearPlane;
	farPlane = farPlane;
}

void Camera::Rotate(float upAngle, float rightAngle) {
	horizontalAngle += rightAngle;
	verticalAngle += upAngle;
	CorrectAngleBoundaries();
}

void Camera::LookAt(glm::vec3 pos) {
	assert(pos != position);
	glm::vec3 direction = glm::normalize(pos - position);
	verticalAngle = glm::radians(asinf(-direction.y));
	horizontalAngle = -glm::radians(atan2f(-direction.x, -direction.z));
	CorrectAngleBoundaries();
}

void Camera::SetPosition(const glm::vec3& pos) {
	position = pos;
}

void Camera::MovePosition(const glm::vec3& movement) {
	position += movement;
}

void Camera::SetAspectRatio(float aspectRatio) {
	assert(aspectRatio > 0.0);
	this->aspectRatio = aspectRatio;
}

const glm::vec3& Camera::GetPosition() const {
	return position;
}


float Camera::GetFov() const {
	return fov;
}

float Camera::GetFrustrumNearPlane() const {
	return nearPlane;
}

float Camera::GetFrustrumFarPlane() const {
	return farPlane;
}

float Camera::GetAspectRatio() const {
	return aspectRatio;
}

glm::mat4 Camera::GetDirection() const {
	glm::mat4 direction;
	direction = glm::rotate(direction, glm::radians(verticalAngle), glm::vec3(1, 0, 0));
	direction = glm::rotate(direction, glm::radians(horizontalAngle), glm::vec3(0, 1, 0));
	return direction;
}

glm::vec3 Camera::GetCamX() const {
	glm::vec4 right = glm::inverse(GetDirection()) * glm::vec4(1, 0, 0, 1);
	return glm::vec3(right);
}

glm::vec3 Camera::GetCamY() const {
	glm::vec4 up = glm::inverse(GetDirection()) * glm::vec4(0, 1, 0, 1);
	return glm::vec3(up);
}

glm::vec3 Camera::GetCamZ() const {
	glm::vec4 camZ = glm::inverse(GetDirection()) * glm::vec4(0, 0, -1, 1);
	return glm::vec3(camZ);
}

glm::mat4 Camera::GetTransMatrix() const {
	return GetProjectionMatrix() * GetViewMatrix();
}

glm::mat4 Camera::GetProjectionMatrix() const {
	return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
}

glm::mat4 Camera::GetViewMatrix() const {
	return GetDirection() * glm::translate(glm::mat4(), -position);
}

void Camera::CorrectAngleBoundaries() {
	horizontalAngle = fmodf(horizontalAngle, 360.0f);
	//fmodf can return negative values, but this will make them all positive
	if (horizontalAngle < 0.0f)
		horizontalAngle += 360.0f;

	if (verticalAngle > maxAngle)
		verticalAngle = maxAngle;
	else if (verticalAngle < -maxAngle)
		verticalAngle = -maxAngle;
}

