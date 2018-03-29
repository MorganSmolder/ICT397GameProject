#pragma once
#include <string>
#include <vector>
#include "Model.h"
#include "RenderModuleStubb.h"
#include "Singleton.h"
#include "TextureManager.h"
#include "vec2.h"

class terrain : public Model
{
	public:
		terrain();
		 ~terrain();
		virtual bool loadModel(std::string filename) = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		virtual terrain * create() const = 0;
	protected:
		float * data;
		std::vector<vec3> plane;
		std::vector<unsigned> planInd;
		std::vector<vec2> texcoords;
		vec3 scale;
		std::string texture;
		unsigned dimensions;

		void genPlane(unsigned size);
		void genPlaneIndicies(unsigned size);
		void genTexCoords();
		void applyScaling(vec3 & scale);
};

