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

	meshes = tocpy.meshes;
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
		setData(model->mMeshes[i]);
	}
		setMinsAndMaxs();
	return(true);
}

void ImportModel::setMinsAndMaxs()
{
	minx = meshes.at(0).vertices.at(0).x();
	minz = meshes.at(0).vertices.at(0).z();
	maxx = meshes.at(0).vertices.at(0).x();
	maxz = meshes.at(0).vertices.at(0).z();
	maxy = meshes.at(0).vertices.at(0).y();
	miny = meshes.at(0).vertices.at(0).y();

	for (unsigned i = 0; i < meshes.size(); i++)
	{
		for (unsigned j = 0; j < meshes.at(i).vertices.size(); j++) {
			if (minx > meshes.at(i).vertices.at(i).x())
			{
				minx = meshes.at(i).vertices.at(i).x();
			}
			if (miny > meshes.at(i).vertices.at(i).y())
			{
				miny = meshes.at(i).vertices.at(i).y();
			}
			if (minz > meshes.at(i).vertices.at(i).z())
			{
				minz = meshes.at(i).vertices.at(i).z();
			}
			if (maxx > meshes.at(i).vertices.at(i).x())
			{
				maxx = meshes.at(i).vertices.at(i).x();
			}

			if (maxy > meshes.at(i).vertices.at(i).y())
			{
				maxy = meshes.at(i).vertices.at(i).y();
			}
			if (maxz > meshes.at(i).vertices.at(i).z())
			{
				maxz = meshes.at(i).vertices.at(i).z();
			}
		}

	}

}

ImportModel* ImportModel::create() const
{
	return new ImportModel(*this);
}

std::vector<vec3>& ImportModel::getVerticies() {
	return meshes.at(0).vertices;
}

void ImportModel::setData(aiMesh *mesh)
{
	Mesh tmp;

	if (mesh->HasPositions())
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			tmp.vertices.push_back(vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z));
		}
	}

	if (mesh->mFaces)
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			tmp.indicies.push_back(mesh->mFaces[i].mIndices[0]);
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
