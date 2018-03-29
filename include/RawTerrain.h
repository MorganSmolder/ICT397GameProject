#pragma once

#include "terrain.h"
#include <fstream>
#include <iostream>
#include <cmath>

class RAWTerrain : public terrain
{
	public:
		RAWTerrain();
		RAWTerrain(const RAWTerrain & tocpy);
		~RAWTerrain();
		virtual bool loadModel(std::string filename);
		virtual void update();
		virtual void render();

		RAWTerrain * create() const;

	private:
		bool loadData(std::string filename);
		std::string parseOptions(std::string file);
		std::string RandomString(unsigned len);
};

