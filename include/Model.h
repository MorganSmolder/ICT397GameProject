#pragma once
#include <vector>
#include <vec3.h>
#include <fstream>
#include <string>
#include <cstdlib>

class Model
{
	public:
		virtual Model * create() const = 0;
		virtual bool loadModel(std::string filename) = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void centerOnPoint(vec3 & point) = 0;
		virtual std::vector<vec3>& getVerticies() = 0;
		float getMinX() { return minx; };
		 float getMinZ() { return minz; };
		 float getMinY() { return miny; };
		 float getMaxX() { return maxx; };
		 float getMaxZ() { return maxz; };
		 float getMaxY() { return maxy; };
	protected:
		float minx, maxx, minz, maxz, miny, maxy;
};

