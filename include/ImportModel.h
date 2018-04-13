#pragma once
#include <Assimp/scene.h>
#include <Assimp/Importer.hpp>
#include <Assimp/postprocess.h>
#include "RenderModuleStubb.h"
#include "Singleton.h"
#include "Model.h"
//#include "vec2.h"
#include "Maths.h"
#include "TextureManager.h"

/**
* @class ImportModel
*
* @brief Imports models.
*
* @author Jarad McKay
* @version 01
* @date 10/03/2018
*/
class ImportModel : public Model
{
public:

	/**
	* @brief Create a model import object.
	*
	* @return ImportModel* - A pointer to the model import object.
	*/
	ImportModel* create() const;

	ImportModel();
	ImportModel(const ImportModel & tocpy);
	~ImportModel();

	/**
	* @brief Load model
	*
	* @param filename(string) - The file name.
	*
	* @return bool - If the file was loaded.
	*/
	bool loadModel(std::string filename);

	/**
	* @brief Set the scale vector.
	*
	* @param toset(vec3 &) - The new vector.
	*
	* @return NONE.
	*/
	void setScale(vec3 & toset);

	/*
	* @brief The update function.
	*
	* @return NONE.
	*/
	void update();

	/*
	* @brief The render function.
	*
	* @param transmat(vec3 &) - The position of the model.
	*
	* @return NONE.
	*/
	void render(const vec3 & transmat);

	/**
	* @brief Get the vertices of the model.
	*
	* @return vector<vec3> & - A vector of positions.
	*/
	std::vector<vec3>& getVerticies();

private:
	/**
	* @brief Setting the max and min values.
	*
	* @return NONE.
	*/
	void setMinsAndMaxs();

	/**
	* @brief Return a random string.
	*
	* @param len(unsigned) - The length required.
	*
	* @return string - The random string.
	*/
	std::string RandomString(unsigned len);

	std::vector<vec3> Vertices; /// Position vector for vertices.
	std::vector<vec2> texCoords; /// Texture coord vector.
	std::vector<vec3> Normals; /// Normals vector.
	std::vector<unsigned> vertIndex; /// Index vector.
	std::string texture; /// Texture.
	const aiScene *model; /// Mesh object.

	/*
	* @brief Setter for vertices.
	*
	* @param mesh (aiMesh *) - The mesh.
	* 
	* @return NONE.
	*/
	void setVertices(aiMesh *mesh);

	/*
	* @brief Setter for texture coords.
	*
	* @param mesh (aiMesh *) - The mesh.
	*
	* @return NONE.
	*/
	void setTexCoords(aiMesh *mesh);

	/*
	* @brief Setter for normals.
	*
	* @param mesh (aiMesh *) - The mesh.
	*
	* @return NONE.
	*/
	void setNormals(aiMesh *mesh);

	/*
	* @brief Setter for indicies.
	*
	* @param mesh (aiMesh *) - The mesh.
	*
	* @return NONE.
	*/
	void setIndexes(aiMesh *mesh);

	/*
	* @brief Get the center point.
	*
	* @param point(vec3 &) - The point you want to center on.
	*
	* @return NONE.
	*/
	void centerOnPoint(vec3 &point);
};

