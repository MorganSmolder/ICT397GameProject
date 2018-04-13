#pragma once
#include <vector>
//#include <vec3.h>
#include "Maths.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include "mat4.h"

/**
* @class MessagingBus
*
* @brief System for sending the messages.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class Model
{
	public:
		/**
		* @brief Virtual method to create the model.
		*
		* @return Model * - The model.
		*/
		virtual Model * create() const = 0;

		/**
		* @brief Virtual method to load the model.
		*
		* @param filename(string) - The filename.
		*
		* @return bool - If it was loaded.
		*/
		virtual bool loadModel(std::string filename) = 0;
		
		/**
		* @brief Virtual method to update.
		*
		* @return NONE.
		*/
		virtual void update() = 0;

		/**
		* @brief Virtual method to render.
		*
		* @param transmat(vec3) - The position being rendered.
		*/
		virtual void render(const vec3 & transmat) = 0;

		/**
		* @brief Virtual method to center the point.
		*
		* @param point(vec3) - The point
		*
		* return NONE.
		*/
		virtual void centerOnPoint(vec3 & point) = 0;

		/**
		* @brief Virtual method to get the vertices.
		*
		* @return vector<vec3> - The vectices.
		*/
		virtual std::vector<vec3>& getVerticies() = 0;

		/**
		* @brief Virtual method to set the scale vector.
		*
		* @param toset(vec3) - The new scale vector.
		*
		* @return NONE.
		*/
		virtual void setScale(vec3 & toset) = 0;

		/**
		* @brief Get min x.
		*
		* @return float - The min x.
		*/
		float getMinX() { return minx; };

		/**
		* @brief Get min z.
		*
		* @return float - The min z.
		*/
		 float getMinZ() { return minz; };

		 /**
		 * @brief Get min y.
		 *
		 * @return float - The min y.
		 */
		 float getMinY() { return miny; };

		 /**
		 * @brief Get max x.
		 *
		 * @return float - The max x.
		 */
		 float getMaxX() { return maxx; };

		 /**
		 * @brief Get max z.
		 *
		 * @return float - The max z.
		 */
		 float getMaxZ() { return maxz; };

		 /**
		 * @brief Get max y.
		 *
		 * @return float - The max y.
		 */
		 float getMaxY() { return maxy; };
	protected:
		float minx, maxx, minz, maxz, miny, maxy; /// Min and max values.
};

