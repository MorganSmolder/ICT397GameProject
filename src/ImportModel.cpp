#include "ImportModel.h"

ImportModel::ImportModel()
{
}

ImportModel::ImportModel(const ImportModel & tocpy)
{
	minx = tocpy.minx;
	maxx = tocpy.maxx;
	minz = tocpy.minz;
	maxz = tocpy.maxz;
	miny = tocpy.miny;
	maxy = tocpy.maxy;

	Vertices = tocpy.Vertices;
	model = tocpy.model;
}
ImportModel::~ImportModel()
{
}

bool ImportModel::loadModel(std::string filename)
{
	Assimp::Importer importer;
	model = importer.ReadFile(filename, NULL); //aiProcessPreset_TargetRealtime_MaxQuality
	if (!model)
	{
		printf("Unable to load mesh: %s\n", importer.GetErrorString());
		return(false);
	}

	for (int i = 0; i < model->mNumMeshes; i++)
	{
		setVertices(model->mMeshes[i]);
	}
		setMinsAndMaxs();
	return(true);
}

void ImportModel::setMinsAndMaxs()
{
	minx = Vertices.at(0).x();
	minz = Vertices.at(0).z();
	maxx = Vertices.at(0).x();
	maxz = Vertices.at(0).z();
	maxy = Vertices.at(0).y();
	miny = Vertices.at(0).y();

	for (unsigned i = 0; i < Vertices.size(); i++)
	{
		if (minx > Vertices.at(i).x())
		{
			minx = Vertices.at(i).x();
		}
		if (miny > Vertices.at(i).y())
		{
			miny = Vertices.at(i).y();
		}
		if (minz > Vertices.at(i).z())
		{
			minz = Vertices.at(i).z();
		}
		if (maxx > Vertices.at(i).x())
		{
			maxx = Vertices.at(i).x();
		}

		if (maxy > Vertices.at(i).y())
		{
			maxy = Vertices.at(i).y();
		}
		if (maxz > Vertices.at(i).z())
		{
			maxz = Vertices.at(i).z();
		}


	}

}


void ImportModel::setVertices(aiMesh *mesh)
{
	if (mesh->HasPositions())
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			Vertices.push_back(vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z));
		}
	}
}

void ImportModel::centerOnPoint(vec3 & point)
{
	setMinsAndMaxs();
	float centerx = (maxx + minx) / 2;
	float centerz = (maxz + minz) / 2;
	float centery = (maxy + miny) / 2;

	float difx = centerx - point.x();
	float difz = centerz - point.z();
	float dify = centery - point.y();

	for (unsigned i = 0; i < Vertices.size(); i++)
	{
		Vertices.at(i).sx(Vertices.at(i).x() - difx);
		Vertices.at(i).sy(Vertices.at(i).y() - dify);
		Vertices.at(i).sz(Vertices.at(i).z() - difz);
	}

	setMinsAndMaxs();
}

void ImportModel::update()
{
}

void ImportModel::render()
{
}
