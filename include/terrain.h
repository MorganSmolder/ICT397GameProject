#pragma once
#include <string>
#include <vector>
#include "Model.h"
#include "RenderModuleStubb.h"
#include "Singleton.h"
#include "TextureManager.h"
//#include "vec2.h"
#include "Maths.h"

/**
* @class terrain
* @brief The terrain data.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class terrain : public Model
{
	public:
		terrain();
		 ~terrain();

		 /**
		 * @brief Virtual method to load models.
		 *
		 * @param filename(string) - The string name.
		 *
		 * @return bool - If the model was loaded.
		 */
		virtual bool loadModel(std::string filename) = 0;

		/**
		* @brief Virtual method for update.
		*
		* @return NONE.
		*/
		virtual void update() = 0;

		/**
		* @brief Virtual method for the renderer.
		*
		* @param transmat(vec3) - The transmat vector.
		*
		* @return NONE.
		*/
		virtual void render(const vec3 & transmat) = 0;

		/**
		* @brief Virtual method for creating terrain.
		*
		* @return terrain* - The terrain data.
		*/
		virtual terrain * create() const = 0;

		/**
		* @brief Center the point.
		*
		* @param point(vec3) - The point.
		*
		* @return NONE.
		*/
		void centerOnPoint(vec3 & point);

		/**
		* @brief Get the vertices.
		*
		* @return vector<vec3> - The verticies.
		*/
		std::vector<vec3>& getVerticies();

		/**
		* @brief Set the scale vector.
		*
		* @param toset(vec3) - The new scale vector.
		*
		* @return NONE.
		*/
		void setScale(vec3 & toset);

	protected:
		float * data; /// Data
		std::vector<vec3> plane; /// The plane of terrain.
		std::vector<unsigned> planInd; /// The texture plan.
		std::vector<vec2> texcoords; /// The texture coords.
		std::vector<float> lights; /// The lights.
		vec3 scale; /// The scale vector.
		unsigned dimensions; /// The size of the map.

		/**
		* @brief Calculate the min and max values.
		*
		* @return NONE.
		*/
		void calcMaxMin();

		/**
		* @brief Generate the plane.
		*
		* @param size(unsigned) - The size of the plane.
		*
		* @return NONE.
		*/
		void genPlane(unsigned size);

		/**
		* @brief Generate the plane indecies.
		*
		* @param size(unsigned) - The size of the plane.
		*
		* @return NONE.
		*/
		void genPlaneIndicies(unsigned size);

		/**
		* @brief Generate the texture coords.
		*
		* @return NONE.
		*/
		void genTexCoords();

		/**
		* @brief Apply the scaling to the heightmap.
		*
		* @param scale(vec3) - The scaling vector.
		*
		* @return NONE.
		*/
		void applyScaling(vec3 & scale);
};

