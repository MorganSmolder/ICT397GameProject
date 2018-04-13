
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
//#include <glm/glm.hpp> // OLD CALL
#include "Maths.h"

//--------------------------------------------------------------------------------------
/**
* @class Singleton
* @brief A singleton data container.
*
* @author Mat DeVene
* @version 01
* @date 02/04/2018
*/
class Camera : public GameObject
{
public:

	Camera(Identifiers & id, vec3 pos, ResourceList & list);

	/**
	* @brief Get the offset vector.
	*
	* @return vec3 - The offset vector.
	*/
	vec3 getCenterOffset();

	/**
	* @brief Set the field of view.
	*
	* @param fov(float) - The field of view.
	*
	* @return NONE.
	*/
	void SetFov(float fov); //sets field of view

	/**
	* @brief Set the frustrum near and far values.
	*
	* @param nearPlane(float) - The near plane.
	* @param farPlane(float) - The far plane.
	*
	* @return NONE.
	*/
	void SetFrustrumNearFar(float nearPlane, float farPlane); //sets the viewing frustrum near and far plane

	/**
	* @brief Rotate the camera.
	*
	* @param - upAngle(float) - The new up angle.
	* @param - rightAngle(float) - The new right angle.
	*
	* @return NONE.
	*/
	void Rotate(float upAngle, float rightAngle); //Changes the direction the camera is facing

	/**
	* @brief Set a new look at vector.
	* 
	* @param pos(vec3) - The new vector.
	* 
	* @return NONE.
	*/
	void LookAt(vec3 pos); // adjusts camera rotation to look at 'pos'

	/**
	* @brief Set the new position.
	*
	* @param pos(vec3) - The new positon.
	*
	* @return NONE.
	*/
	void SetPosition(const vec3& pos);

	/**
	* @brief Set the new aspect ratio.
	*
	* @param aspectRation(float) - The new aspect ratio.
	*
	* @return NONE.
	*/
	void SetAspectRatio(float aspectRatio);

	/**
	* @brief Get the field of view.
	*
	* @return float - The field of view.
	*/
	float GetFov() const;

	/**
	* @brief Get the near value for the plane.
	*
	* @return float - The near value.
	*/
	float GetFrustrumNearPlane() const;

	/**
	* @brief Get the far value for the plane.
	*
	* @return float - The far value.
	*/
	float GetFrustrumFarPlane() const;

	/**
	* @brief Get the aspect ratio.
	*
	* @return float - The aspect ratio.
	*/
	float GetAspectRatio() const;

	/**
	* @brief Get the direction of the camera.
	*
	* @return mat4 - The direction matrix.
	*/
	mat4 GetDirection() const; //rotation matrix for the direction of the camera

	/**
	* @brief Get the x vector of the camera.
	*
	* @return vec3 - The x vector.
	*/
	vec3 GetCamX() const; //vector for cameras X axis (left / right)

	/**
	* @brief Get the y vector of the camera.
	*
	* @return vec3 - The y vector.
	*/
	vec3 GetCamY() const; //vector for camera's Y axis (up/down

	/**
	* @brief Get the z vector of the camera.
	*
	* @return vec3 - The z vector.
	*/
	vec3 GetCamZ() const; //vector for the cameras Z axis (what it is looking at)

	/**
	* @brief Get the translation matrix.
	*
	* @return mat4 - The translation matrix.
	*/
	mat4 GetTransMatrix() const; //camera's transformation matrix

	/**
	* @brief Get the projection matrix.
	*
	* @return mat4 - The projection matrix.
	*/
	mat4 GetProjectionMatrix() const; //perspective projection transformation matrix

	/**
	* @brief Get the view matrix.
	*
	* @return mat4 - Get the view matrix.
	*/
	mat4 GetViewMatrix() const; //translation and rotation matrix



	/////////

	/**
	* @brief The update function.
	*
	* @param time(float) - The system time.
	*
	* @return NONE.
	*/
	void update(float time);

	/**
	* @brief Renderer function.
	*
	* @return NONE.
	*/
	void render();

	/**
	* @brief Call the GL look at function.
	*
	* @return NONE.
	*/
	void callGLLookAt();
private:
	float moveSpeed; /// The move speed of the camera.
	float rotateSpeed; /// The rotation speed.
	 
	/**
	* @brief Correct the angle boundaries.
	*
	* @return NONE.
	*/
	void CorrectAngleBoundaries();
	float fov; /// The field of view.
	float aspectRatio; /// Aspect ratio.
	float nearPlane; /// The near plane.
	float farPlane; /// The far plane.
	float horizontalAngle; /// The horizontal angle.
	float verticalAngle; /// The verticle angle.
	const float maxAngle = 80.0f; /// Max angle for field of view.
	Camera (const Camera &cam) {};
    Camera &operator = (const Camera &cam) {};
};

#endif