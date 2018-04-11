#include "Camera.h"

#include <math.h>



Camera::Camera(Identifiers & id, vec3 pos, ResourceList & list) : GameObject(id, pos, list)
{
	rotateSpeed = 2.0f;
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
		target += -GetCamZ()* moveSpeed;
	}

	if (this->moveRight) {
		target += GetCamX()* moveSpeed;
	}
	else
	if (this->moveLeft) {
		target -= GetCamX()* moveSpeed;
	}

	if (this->lookDown) {
		target += -glm::vec3(0, 1, 0)* moveSpeed;
	}
	else
	if (this->lookUp) {
		target += glm::vec3(0, 1, 0)* moveSpeed;
	}

	pos += (target * (time * speedDecay));
	target -= (target * (time * speedDecay));


	callGLLookAt();
}

void Camera::render() {


}

void Camera::callGLLookAt()
{
	Singleton<RenderModuleStubb>::getInstance()->callLookAt(vec3(pos.x(), pos.y(), pos.z()), 
				vec3(pos.x() + GetCamZ().x, pos.y() + GetCamZ().y, pos.z() + GetCamZ().z),
				vec3(GetCamY().x, GetCamY().y, GetCamY().z));

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
	glm::vec3 direction = glm::normalize(pos - glm::vec3(this->pos.x(), this->pos.y(), this->pos.z()));
	verticalAngle = glm::radians(asinf(-direction.y));
	horizontalAngle = -glm::radians(atan2f(-direction.x, -direction.z));
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
	return GetDirection() * glm::translate(glm::mat4(), glm::vec3(pos.x() * -1, pos.y() * -1, pos.z() * -1));
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