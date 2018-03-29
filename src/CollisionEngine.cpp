#include "CollisionEngine.h"



CollisionEngine::CollisionEngine()
{
}


CollisionEngine::~CollisionEngine()
{
}

void CollisionEngine::setHeightMap(std::vector<vec3> & toset) {
	std::map<int, float> tmp;

	for (unsigned i = 0; i < toset.size(); i++) {
		if (heightmap.count((int) toset.at(i).x()) == 0) heightmap[(int) toset.at(i).x()] = tmp;
		heightmap[(int) toset.at(i).x()][(int) toset.at(i).z()] = (int) toset.at(i).y();
	}

	std::map<int, std::map<int, float> >::iterator mapit = heightmap.begin();

	int sample1 = mapit->first;
	++mapit;
	int sample2 = mapit->first;

	step = abs(sample2 - sample1);

	//for (std::map<int, std::map<int, float> >::iterator mapit = heightmap.begin(); mapit != heightmap.end(); ++mapit) {
	//	std::cout << "row: " << mapit->first << std::endl;
	//	for (std::map<int, float>::iterator mapit2 = mapit->second.begin(); mapit2 != mapit->second.end(); ++mapit2) {
	//		std::cout << mapit2->first << " value: " << mapit2->second << std::endl;
	//	}
	//}
}

void CollisionEngine::update(GameObject* & toupdate) {
	int x = (int)toupdate->getPos().x();
	int z = (int)toupdate->getPos().z();

	int lky1 = heightmap.lower_bound(x)->first;
	int lky2 = heightmap.at(lky1).lower_bound(z)->first;

	int uk1 = heightmap.upper_bound(x)->first;
	int uk2 = heightmap.at(uk1).upper_bound(z)->first;

	//float ny = linearInterpolate(heightmap.at(lky1).at(lky2), heightmap.at(uk1).at(uk2), toupdate->getPos().x()/ heightmap.at(uk1).at(uk2));

	toupdate->setPos(vec3(toupdate->getPos().x(), heightmap[lky1][lky2], toupdate->getPos().z()));

	if (toupdate->getType() == "CAM") {
		//std::cout << "ob x " << (int)toupdate->getPos().x() << std::endl;
		//std::cout << "ob z " << (int)toupdate->getPos().z() << std::endl;

		//std::cout << ny << std::endl;

		//std::cout << "lower x: " << lky1 << " lower z: " << lky2 << std::endl;
		//std::cout << "upper x: " << uk1 << " upper z: " << uk2 << std::endl;
	}
}

float CollisionEngine::linearInterpolate(float a, float b, float f)
{
	return a + f * (b - a);
}