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

<<<<<<< HEAD
	meshes = tocpy.meshes;
=======
	Vertices = tocpy.Vertices;
>>>>>>> 9217a834900c7ea061baa69ba93f23777d66f6ae
	model = tocpy.model;
}
ImportModel::~ImportModel()
{
}

bool ImportModel::loadModel(std::string filename)
{
	Assimp::Importer importer;
<<<<<<< HEAD
	model = importer.ReadFile(filename, NULL); //aiProcessPreset_TargetRealtime_MaxQuality
=======
	model = importer.ReadFile(filename, aiProcessPreset_TargetRealtime_MaxQuality); //see assimp.sourceforge.net/lib_html/postprocess_8h.html for more info.
>>>>>>> 9217a834900c7ea061baa69ba93f23777d66f6ae
	if (!model)
	{
		printf("Unable to load mesh: %s\n", importer.GetErrorString());
		return(false);
	}

	for (int i = 0; i < model->mNumMeshes; i++)
	{
<<<<<<< HEAD
		setData(model->mMeshes[i]);
	}
		setMinsAndMaxs();
=======
		setVertices(model->mMeshes[i]);
		setTexCoords(model->mMeshes[i]);
		setNormals(model->mMeshes[i]);
		setIndexes(model->mMeshes[i]);
	}
		setMinsAndMaxs();

		delete model; // Further data I guess isn't used.
>>>>>>> 9217a834900c7ea061baa69ba93f23777d66f6ae
	return(true);
}

void ImportModel::setMinsAndMaxs()
{
<<<<<<< HEAD
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
=======
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

>>>>>>> 9217a834900c7ea061baa69ba93f23777d66f6ae

	}

}

<<<<<<< HEAD
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
=======

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

//this one im not sure is right, rest should be fine
void ImportModel::setIndexes(aiMesh *mesh)
{
	if (mesh->HasFaces())
	{
		for (int i = 0; i < mesh->mNumFaces; i++)
		{
			Normals.push_back(vec3(mesh->mFaces[i].mIndices[0], mesh->mFaces[i].mIndices[1], mesh->mFaces[i].mIndices[2]));
		}
	}
}

void ImportModel::setNormals(aiMesh *mesh)
{
	if (mesh->HasNormals())
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			Normals.push_back(vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z));
		}
	}
}

void ImportModel::setTexCoords(aiMesh *mesh)
{
	if (mesh->HasTextureCoords(0))
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			texCoords.push_back(vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y));
>>>>>>> 9217a834900c7ea061baa69ba93f23777d66f6ae
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
