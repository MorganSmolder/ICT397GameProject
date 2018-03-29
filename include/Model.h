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
};

