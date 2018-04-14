#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"
#include "Identifiers.h"
#include "ResourceList.h"
#include "RenderModuleStubb.h"
#include "Singleton.h"
#include <glm/glm.hpp>

//--------------------------------------------------------------------------------------

/**
* @class Camera
* @brief Class for creating updating and handling the camera object.
*
* @author Mat DeVene
* @version 01
* @date 02/04/2018
*/
class Camera : public GameObject
{
public:

	Camera(Identifiers & id, vec3 pos, ResourceList & list);

<<<<<<< HEAD
	vec3 getCenterOffset();
	void SetFov(float fov); //sets field of view
	void SetFrustrumNearFar(float nearPlane, float farPlane); //sets the viewing frustrum near and far plane
	void Rotate(float upAngle, float rightAngle); //Changes the direction the camera is facing
	void LookAt(glm::vec3 pos); // adjusts camera rotation to look at 'pos'
	void SetPosition(const vec3& pos);
	void SetAspectRatio(float aspectRatio);
	void stop();

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

=======
	/**
	* @brief Get the center offset vector.
	*
	* @return vec3 - The center offset vector.
	*/
	vec3 getCenterOffset();

	/**
	* @brief Set the field of view
	*
	* @param fov - The new FoV.
	*/
	void SetFov(float fov); //sets field of view

	/**
	* @brief Sets the viewing frustrum near and far plane.
	*
	* @param nearPlane - The nearest plane.
	* @param farPlane - The furthest Plane.
	*/
	void SetFrustrumNearFar(float nearPlane, float farPlane); //sets the viewing frustrum near and far plane
	
	/**
	* @brief Changes the direction the camera is facing.
	*
	* @param upAngle
	* @param rightAngle
	*/
	void Rotate(float upAngle, float rightAngle); //Changes the direction the camera is facing

	/**
	* @brief Adjusts camera rotation to look at 'pos'.
	*
	* @param pos - The position.
	*/
	void LookAt(glm::vec3 pos); // adjusts camera rotation to look at 'pos'

	/**
	* @brief Set the position.
	*
	* @param pos - The new position.
	*/
	void SetPosition(const vec3& pos);

	/**
	* @brief Set the aspect ratio.
	*
	* @param aspectratio - The new aspect ratio.
	*/
	void SetAspectRatio(float aspectRatio);


	/**
	* @brief Get the FoV.
	*
	* @return float - FoV.
	*/
	float GetFov() const;

	/**
	* @brief Get the frustrum near plane
	*
	* @return float - Frustrum near plane.
	*/
	float GetFrustrumNearPlane() const;

	/**
	* @brief Get the frustrum far plane.
	*
	* @return float - Frustrum far plane.
	*/
	float GetFrustrumFarPlane() const;

	/**
	* @brief Get the aspect ratio.
	*
	* @return float - The aspect ratio.
	*/
	float GetAspectRatio() const;

	/**
	* @brief Rotation matrix for the direction of the camera.
	*
	* @return mat4 - The direction
	*/
	glm::mat4 GetDirection() const; //rotation matrix for the direction of the camera

	/**
	* @brief Vector for cameras X axis (left / right).
	*
	* @return vec3 - The camera x axis position
	*/
	glm::vec3 GetCamX() const; //vector for cameras X axis (left / right)

	/**
	* @brief Vector for camera's Y axis (up / down).
	*
	* @return vec3 - The camera y axis position
	*/
	glm::vec3 GetCamY() const; //vector for camera's Y axis (up/down)

	/**
	* @brief Vector for the cameras Z axis (what it is looking at).
	*
	* @return vec3 - The camera y axis position
	*/
	glm::vec3 GetCamZ() const; //vector for the cameras Z axis (what it is looking at)

	/**
	* @brief Camera's transformation matrix.
	*
	* @return mat4 - The cameras transformation matrix.
	*/
	glm::mat4 GetTransMatrix() const; //camera's transformation matrix

	/**
	* @brief Perspective projection transformation matrix.
	*
	* @return mat4 - The cameras projection matrix.
	*/
	glm::mat4 GetProjectionMatrix() const; //perspective projection transformation matrix

	/**
	* @brief Translation and rotation matrix.
	*
	* @return mat4 - The cameras view matrix.
	*/
	glm::mat4 GetViewMatrix() const; //translation and rotation matrix


	/**
	* @brief Update function for camera.
	*
	* @param time - System time.
	*/
>>>>>>> origin/particles
	void update(float time);

	/**
	* @brief Call render function.
	*/
	void render();

	/**
	* @brief Look at function.
	*/
	void callGLLookAt();
private:
<<<<<<< HEAD
	float moveSpeed;
	float rotateSpeed;
	float speedDecay;
	bool moveForward;
	bool moveBack;
	bool moveRight;
	bool moveLeft;
	bool lookDown;
	bool lookUp;


	void CorrectAngleBoundaries();
	float fov;
	float aspectRatio;
	float nearPlane;
	float farPlane;
	float horizontalAngle;
	float verticalAngle;
	float maxlspeed;
=======
	/// Move speed of camera.
	float moveSpeed;
	/// Rotation speed of camera.
	float rotateSpeed;
	/// Move speed decay rate.
	float speedDecay;
	/// If moving foward.
	bool moveForward;
	/// If moving backwards.
	bool moveBack;
	/// If moving right.
	bool moveRight;
	/// If moving left.
	bool moveLeft;
	/// If looking down.
	bool lookDown;
	/// If looking up.
	bool lookUp;


	/**
	* @brief Correcting the angles at boundaries.
	*/
	void CorrectAngleBoundaries();
	/// Field of View.
	float fov;
	/// Aspect ratio.
	float aspectRatio;
	/// Near plane.
	float nearPlane;
	/// Far plane.
	float farPlane;
	/// Horizontal Angle.
	float horizontalAngle;
	/// Verticle Angle.
	float verticalAngle;
	/// Max angle.
>>>>>>> origin/particles
	const float maxAngle = 60.0f;
	Camera(const Camera &cam) {};
	Camera &operator = (const Camera &cam) {};
};

#endif