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
		virtual void render(const vec3 & transmat) = 0;
		virtual terrain * create() const = 0;
		void centerOnPoint(vec3 & point);
		std::vector<vec3>& getVerticies();
		void setScale(vec3 & toset);

	protected:
		float * data;
		std::vector<vec3> plane;
		std::vector<unsigned> planInd;
		std::vector<vec2> texcoords;
		std::vector<float> lights;
		vec3 scale;
		unsigned dimensions;
		void calcMaxMin();

		void genPlane(unsigned size);
		void genPlaneIndicies(unsigned size);
		void genTexCoords();
		void applyScaling(vec3 & scale);
};

