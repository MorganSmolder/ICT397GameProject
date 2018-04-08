
//Shays shitty camera class.
//Standing in for mat's camera

#ifndef CAMERA_H
#define CAMERA_H

#define PI 3.1415962654

#include "GameObject.h"
#include "Identifiers.h"
#include "ResourceList.h"
#include "RenderModuleStubb.h"
#include "Singleton.h"
#include <glm/glm.hpp>

//--------------------------------------------------------------------------------------

class Camera : public GameObject
{
public:

	Camera(Identifiers & id, vec3 pos, ResourceList & list);

	vec3 getCenterOffset();
	void SetFov(float fov); //sets field of view
	void SetFrustrumNearFar(float nearPlane, float farPlane); //sets the viewing frustrum near and far plane
	void Rotate(float upAngle, float rightAngle); //Changes the direction the camera is facing
	void LookAt(glm::vec3 pos); // adjusts camera rotation to look at 'pos'
	void SetPosition(const vec3& pos);
	void SetAspectRatio(float aspectRatio);

	float GetFov() const;
	float GetFrustrumNearPlane() const;
	float GetFrustrumFarPlane() const;
	float GetAspectRatio() const;
	glm::mat4 GetDirection() const; //rotation matrix for the direction of the camera
	glm::vec3 GetCamX() const; //vector for cameras X axis (left / right)
	glm::vec3 GetCamY() const; //vector for camera's Y axis (up/down
	glm::vec3 GetCamZ() const; //vector for the cameras Z axis (what it is looking at)
	glm::mat4 GetTransMatrix() const; //camera's transformation matrix
	glm::mat4 GetProjectionMatrix() const; //perspective projection transformation matrix
	glm::mat4 GetViewMatrix() const; //translation and rotation matrix



	/////////
	void update(float time);
	void render();
	void callGLLookAt();
private:
	float moveSpeed;
	float rotateSpeed;

	void CorrectAngleBoundaries();
	float fov;
	float aspectRatio;
	float nearPlane;
	float farPlane;
	float horizontalAngle;
	float verticalAngle;
	const float maxAngle = 80.0f;
	Camera (const Camera &cam) {};
    Camera &operator = (const Camera &cam) {};
};

#endif