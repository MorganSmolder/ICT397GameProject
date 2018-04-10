
#include "Camera.h"

#include <math.h>

Camera::Camera(Identifiers & id, vec3 pos, ResourceList & list) : GameObject(id, pos, list)
{
	
	rotateSpeed = 2.0f;
	moveSpeed = 2.0f;

	fov = 50.0f;
	nearPlane = 0.01f;
	farPlane = 100.0f;
	aspectRatio = (4.0f / 3.0f);
	horizontalAngle = 0.0f;
	verticalAngle = 0.0f;
}

void Camera::update(float time) {
	msgrcvr();

	MessagingBus* tmp = Singleton<MessagingBus>::getInstance();
	Message tmpm;

	while (tmp->hasMessage(id)) {
		
		tmpm = tmp->getMessage(id);

		if (tmpm.getInstruction() == "MVF") {
			target += GetCamZ()* moveSpeed;
		}
		else
		if (tmpm.getInstruction() == "MVB") {
			target += -GetCamZ()* moveSpeed;
		}
		else
		if (tmpm.getInstruction() == "MVR") {
			target += GetCamX()* moveSpeed;
		}
		else
		if (tmpm.getInstruction() == "MVL") {
			target -= GetCamX()* moveSpeed;
		}
		else
		if (tmpm.getInstruction() == "LD") {
			target += -vec3(0, 1, 0) * moveSpeed;
		}
		else
		if (tmpm.getInstruction() == "LU") {
			target += vec3(0, 1, 0)* moveSpeed;
		}
		else
		if (tmpm.getInstruction() == "LX") {
			horizontalAngle -= tmpm.getData().fdata * time * rotateSpeed;
		}
		else
		if (tmpm.getInstruction() == "LY") {
			verticalAngle -= tmpm.getData().fdata * time * rotateSpeed;
		}
	}

	pos += (target * time);
	target -= (target * time);
	
	callGLLookAt();
}

void Camera::render() {

	
}

//----------------------------------------------------------------------------------------
//  Redisplay new camera view
//----------------------------------------------------------------------------------------
void Camera::callGLLookAt()
{
	targetlook = GetCamZ();

	vec3 camUpVec = GetCamY();

	Singleton<RenderModuleStubb>::getInstance()->callLookAt(vec3(pos.x(), pos.y(), pos.z()), 
				vec3(pos.x() + targetlook.x(), pos.y() + targetlook.y(), pos.z() + targetlook.z()),
				vec3(camUpVec.x, camUpVec.y, camUpVec.z));
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

void Camera::LookAt(vec3 pos) {
	assert(pos != position);
	vec3 direction = Maths::normalize(pos - vec3(this->pos.x(), this->pos.y(), this->pos.z()));
	verticalAngle = Maths::radians(asinf(-direction.y));
	horizontalAngle = -Maths::radians(atan2f(-direction.x, -direction.z));
	CorrectAngleBoundaries();
}

void Camera::SetPosition(const vec3& pos) {
	this->pos = pos;
}

void Camera::SetAspectRatio(float aspectRatio) {
	assert(aspectRatio > 0.0);
	this->aspectRatio = aspectRatio;
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

mat4 Camera::GetDirection() const {
	mat4 direction;
	direction = Maths::rotate(direction, Maths::radians(verticalAngle), vec3(1, 0, 0));
	direction = Maths::rotate(direction, Maths::radians(horizontalAngle), vec3(0, 1, 0));
	return direction;
}

vec3 Camera::GetCamX() const {
	vec4 right = Maths::inverse(GetDirection()) * vec4(1, 0, 0, 1);
	return vec3(right);
}

vec3 Camera::GetCamY() const {
	vec4 up = Maths::inverse(GetDirection()) * vec4(0, 1, 0, 1);
	return vec3(up);
}

vec3 Camera::GetCamZ() const {
	vec4 camZ = Maths::inverse(GetDirection()) * vec4(0, 0, -1, 1);
	return vec3(camZ);
}

mat4 Camera::GetTransMatrix() const {
	return GetProjectionMatrix() * GetViewMatrix();
}

mat4 Camera::GetProjectionMatrix() const {
	return Maths::perspective(Maths::radians(fov), aspectRatio, nearPlane, farPlane);
}

mat4 Camera::GetViewMatrix() const {
	return GetDirection() * Maths::translate(mat4(), vec3(pos.x() * -1, pos.y() * -1, pos.z() * -1));
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

vec3 Camera::getCenterOffset() {
	return vec3(0, 10, 0);
}