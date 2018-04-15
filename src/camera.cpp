#include "Camera.h"

#include <math.h>



Camera::Camera(Identifiers & id, vec3 pos, ResourceList & list) : GameObject(id, pos, list)
{
	rotateSpeed = 3.0f;
	moveSpeed = 3.0f;
	speedDecay = 7.0f;
	fov = 50.0f;
	nearPlane = 0.01f;
	farPlane = 100.0f;
	aspectRatio = (4.0f / 3.0f);
	horizontalAngle = 0.0f;
	verticalAngle = 0.0f;
	moveForward = false;
	moveBack = false;
	moveRight = false;
	moveLeft = false;
	lookDown = false;
	lookUp = false;
}

void Camera::update(float time) {
	msgrcvr();

	MessagingBus* tmp = Singleton<MessagingBus>::getInstance();
	Message tmpm;

	while (tmp->hasMessage(id)) {

		tmpm = tmp->getMessage(id);

		if (tmpm.getInstruction() == "MVF") {
			this->moveForward = true;
		}
		else
		if (tmpm.getInstruction() == "SMF") {
			this->moveForward = false;
		}
		else
		if (tmpm.getInstruction() == "MVB") {
			this->moveBack = true;
		}
		else
		if (tmpm.getInstruction() == "SMB") {
			this->moveBack = false;
		}
		else
		if (tmpm.getInstruction() == "MVR") {
			this->moveRight = true;
		}
		else
		if (tmpm.getInstruction() == "SMR") {
			this->moveRight = false;
		}
		else
		if (tmpm.getInstruction() == "MVL") {
			this->moveLeft = true;
		}
		else
		if (tmpm.getInstruction() == "SML") {
			this->moveLeft = false;
		}
		else
		if (tmpm.getInstruction() == "LD") {
			this->lookDown = true;
		}
		else
		if (tmpm.getInstruction() == "SLD") {
			this->lookDown = false;
		}
		else
		if (tmpm.getInstruction() == "LU") {
			this->lookUp = true;
		}
		else
		if (tmpm.getInstruction() == "SLU") {
			this->lookUp = false;
		}
		else
		if (tmpm.getInstruction() == "LX") {
			horizontalAngle -= tmpm.getData().fdata * time * rotateSpeed;
		}
		else
		if (tmpm.getInstruction() == "LY") {
			verticalAngle -= tmpm.getData().fdata * time * rotateSpeed;
			if (verticalAngle <= -maxAngle && tmpm.getData().fdata < 0) verticalAngle = -maxAngle;
			if (verticalAngle >= maxAngle && tmpm.getData().fdata > 0) verticalAngle = maxAngle;
		}
	}

	if (this->moveForward) {
		target += GetCamZ()* moveSpeed;
	}
	else
	if (this->moveBack) {
		target += (GetCamZ()* moveSpeed) * -1;
	}

	if (this->moveRight) {
		target += GetCamX()* moveSpeed;
	}
	else
	if (this->moveLeft) {
		target -= GetCamX()* moveSpeed;
	}

	if (this->lookDown) {
		target += (vec3(0, 1, 0)* moveSpeed) * -1;
	}
	else
	if (this->lookUp) {
		target += vec3(0, 1, 0)* moveSpeed;
	}

	pos += (target * (time * speedDecay));
	target -= (target * (time * speedDecay));


	callGLLookAt();
}

void Camera::render() {
	//Singleton<RenderModuleStubb>::getInstance()->RenderFacingCamera();

	//Singleton<RenderModuleStubb>::getInstance()->StopRenderFacingCamera();
}

void Camera::callGLLookAt()
{
	Singleton<RenderModuleStubb>::getInstance()->callLookAt(vec3(pos.x(), pos.y(), pos.z()), 
				vec3(pos.x() + GetCamZ().x(), pos.y() + GetCamZ().y(), pos.z() + GetCamZ().z()),
				vec3(GetCamY().x(), GetCamY().y(), GetCamY().z()));

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
	verticalAngle = Maths::radians(asinf(-direction.y()));
	horizontalAngle = -Maths::radians(atan2f(-direction.x(), -direction.z()));
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