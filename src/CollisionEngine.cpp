#include "CollisionEngine.h"



CollisionEngine::CollisionEngine()
{
	hasHMap == false;
}


CollisionEngine::~CollisionEngine()
{
}

void CollisionEngine::setHeightMap(std::vector<vec3> & toset) {
	std::map<float, float> tmp;

	maxx = toset.at(0).x();
	minx = toset.at(0).x();
	maxz = toset.at(0).z();
	minz = toset.at(0).z();

	for (unsigned i = 0; i < toset.size(); i++) {
		if (heightmap.count(toset.at(i).x()) == 0) heightmap[ toset.at(i).x()] = tmp;
		heightmap[toset.at(i).x()][toset.at(i).z()] = toset.at(i).y();
		if(toset.at(i).x() > maxx){
			maxx = toset.at(i).x();
		}
		if (toset.at(i).z() > maxz) {
			maxz = toset.at(i).z();
		}
		if (toset.at(i).x() < minx) {
			minx = toset.at(i).x();
		}
		if (toset.at(i).z() < minz) {
			minz = toset.at(i).z();
		}
	}

	hasHMap = true;
}

void CollisionEngine::update(GameObject* & toupdate, std::vector<GameObject*> collGO, float time) {
	float x = toupdate->getPos().x();
	float z = toupdate->getPos().z();

	if (x < maxx && x > minx && z > minz && z < maxz && hasHMap){
		HMPos hmloc = findHMLocation(toupdate->getPos());

		float y = findBarycenter(toupdate->getPos(), hmloc);

		toupdate->setPos(vec3(toupdate->getPos().x(), y + toupdate->getCenterOffset().y(), toupdate->getPos().z()));
		toupdate->setTarget(vec3(toupdate->getTarget().x(), 0, toupdate->getTarget().z()));
	}

	AABB updateb;

	if (toupdate->getModel() == NULL) updateb = AABB(toupdate->getPos().x() + 1.5, toupdate->getPos().x() - 1.5,
		toupdate->getPos().y() + 1.5, toupdate->getPos().y() - 1.5,
		toupdate->getPos().z() + 1.5, toupdate->getPos().z() - 1.5);
	else updateb = AABB(toupdate->getModel()->getMaxX(), toupdate->getModel()->getMinX(),
		toupdate->getModel()->getMaxY(), toupdate->getModel()->getMinY(),
		toupdate->getModel()->getMaxZ(), toupdate->getModel()->getMinZ());

	vec3 tmpos = toupdate->getPos();

	toupdate->update(time);
	//std::cout << toupdate->getPos().x() << " " << toupdate->getPos().y() << " " << toupdate->getPos().z() << std::endl;

	for (unsigned i = 0; i < collGO.size(); i++) {
		if (collGO.at(i)->getID() != toupdate->getID() && collGO.at(i)->getModel() != NULL) {
			if (updateb.xmax >= collGO.at(i)->getModel()->getMinX() && updateb.xmin <= collGO.at(i)->getModel()->getMaxX()
				|| updateb.zmax >= collGO.at(i)->getModel()->getMinZ() && updateb.zmin <= collGO.at(i)->getModel()->getMaxZ()) {
				//toupdate->setPos(tmpos);
				//toupdate->setTarget(vec3());
			}
		}
	}

}

HMPos CollisionEngine::findHMLocation(const vec3 & pos) {
	std::map<float, std::map<float, float> >::iterator mapit1 = heightmap.lower_bound(pos.x());
	float tmpky1upr = mapit1->first;
	mapit1--;
	float tmpk1lwr = mapit1->first;

	std::map<float, float>::iterator mapit2 = heightmap.at(tmpky1upr).lower_bound(pos.z());
	float tmpky2upr = mapit2->first;
	mapit2--;
	float tmpk2lwr = mapit2->first;

	HMPos tmp;
	tmp.tl = vec2(tmpky1upr, tmpk2lwr);
	tmp.br = vec2(tmpk1lwr, tmpky2upr);

	return tmp;
}

float CollisionEngine::findBarycenter(const vec3 & ppos, HMPos & pos) {
	vec3 tr1, tr2, tr3;

	//top of quad
	if (ppos.x() <= (1 - ppos.z())) {
		tr1.sx(pos.tl.x());
		tr1.sz(pos.br.y());
		tr1.sy(heightmap.at(pos.tl.x()).at(pos.br.y()));
	}
	else {
		tr1.sx(pos.br.x());
		tr1.sz(pos.tl.y());
		tr1.sy(heightmap.at(pos.br.x()).at(pos.tl.y()));
	}

	tr2.sx(pos.tl.x());
	tr2.sz(pos.tl.y());
	tr2.sy(heightmap.at(pos.tl.x()).at(pos.tl.y()));

	tr3.sx(pos.br.x());
	tr3.sz(pos.br.y());
	tr3.sy(heightmap.at(pos.br.x()).at(pos.br.y()));

	float det = ((tr2.z() - tr3.z())*(tr1.x() - tr3.x()) + (tr3.x() - tr2.x())*(tr1.z() - tr3.z()));
	float a1 = ((tr2.z() - tr3.z())*(ppos.x() - tr3.x()) + (tr3.x() - tr2.x())*(ppos.z() - tr3.z())) / det;
	float a2 = ((tr3.z() - tr1.z())*(ppos.x() - tr3.x()) + (tr1.x() - tr3.x())*(ppos.z() - tr3.z())) / det;
	float a3 = 1.0f - a1 - a2;
	
	return a1 * tr1.y() + a2*tr2.y() + a3*tr3.y();
}
