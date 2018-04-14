#pragma once

#include "terrain.h"
#include <fstream>
#include <iostream>
#include <cmath>

class RAWTerrain : public terrain
{
	public:
		RAWTerrain();
		~RAWTerrain();
		virtual bool loadModel(std::string filename);
		virtual void update();
		virtual void render(const vec3 & transmat);

		RAWTerrain * create() const;

	private:
		std::string multitexture;
		std::string detailmap;
		bool loadData(std::string filename);
		std::string parseOptions(std::string file);
		std::string RandomString(unsigned len);
		std::vector<std::string> images;
		RAWTerrain(const RAWTerrain & tocpy);
};

