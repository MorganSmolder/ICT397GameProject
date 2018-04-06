
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

	//----------------------------------------------------------------------------------
	
	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------


	// set step and rotation size
	/*
	void SetRotateSpeed (const GLdouble &tempSpeed) {m_rotateSpeed = tempSpeed;}
	void SetMoveSpeed (const GLdouble &tempSpeed) {m_moveSpeed = tempSpeed;}



	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	GLdouble GetLR () {return pos.x();}
	GLdouble GetUD () {return pos.y();}
	GLdouble GetFB () {return pos.z();}	
	
	// position the camera
	void Position (GLdouble const & tempX,
				   GLdouble const & tempY,
				   GLdouble const & tempZ,
				   GLdouble const & tempAngle, 
				   GLdouble const & tempAnglUD = 0);

	// check whether ok to move
	void CheckCamera();

	// Used to pass direction to move or rotate  (i.e. 1, -1 or 0)
	void DirectionFB(int const & tempMove);
	void DirectionLR(int const & tempMove);
	void DirectionUD(int const & tempMove);
	void DirectionRotateLR(GLdouble const & tempMove);
	void DirectionLookUD(int const & tempMove);

	GLdouble* getLX(){ return &m_lookX; };
	GLdouble* getLY(){ return &m_lookY; };
	GLdouble* getLZ(){ return &m_lookZ; };

	void setLX(GLdouble x){  m_lookX = x; };
	void setLY(GLdouble y){ m_lookY = y; };
	void setLZ(GLdouble z){ m_lookZ = z; };

	
	void setX(GLdouble newx){ pos.sx(newx); };
	void setY(GLdouble newy){ pos.sy(newy); };
	void setZ(GLdouble newz){ pos.sz(newz); };
	*/
	/////////

	void SetFov(float fov); //sets field of view
	void SetFrustrumNearFar(float nearPlane, float farPlane); //sets the viewing frustrum near and far plane
	void Rotate(float upAngle, float rightAngle); //Changes the direction the camera is facing
	void LookAt(glm::vec3 pos); // adjusts camera rotation to look at 'pos'
	void SetPosition(const glm::vec3& pos);
	void MovePosition(const glm::vec3& movement);
	void SetAspectRatio(float aspectRatio);

	const glm::vec3& GetPosition() const;
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
	GLdouble moveSpeed;
	/*
	// rotation variables
	GLdouble m_rotateAngleLR;
	GLdouble m_deltaAngleLR;
	GLdouble m_rotateAngleUD;	
	GLdouble m_deltaAngleUD;

	GLdouble m_lookX, m_lookY,m_lookZ;
	GLdouble m_lookXX, m_lookYY, m_lookZZ;
	GLdouble m_deltaMoveLR;
	GLdouble m_deltaMoveFB;
	GLdouble m_deltaMoveUD;
	GLdouble m_direction;

	// movement speed (step size)
	GLdouble m_rotateSpeed;
	
	
	// is it ok to move
	bool MoveFBOK();
	bool MoveLROK();
	bool MoveUDOK();
	bool RotateLROK();
	bool LookUDOK();

	// move around the world
	void MoveFB();
	void MoveLR();
	void MoveUD();
	void RotateLR();
	void LookUD();


	// resets camera
	void ResetXYZ();
	// display new view

	//----------------------------------------------------------------------------------

    // Privatised copy constructor and assignment operator
    */

	void CorrectAngleBoundaries();
	glm::vec3 position;
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