#pragma once
#include <Assimp/scene.h>
#include <Assimp/Importer.hpp>
#include <Assimp/postprocess.h>
#include "RenderModuleStubb.h"
#include "Singleton.h"
#include "Model.h"
#include "vec2.h"
#include "TextureManager.h"

<<<<<<< HEAD
=======
/**
* @class ImportModel
* @brief Class for importing models from assimp
*
* @author Jarad Mckay
* @version 01
* @date 02/04/2018
*/
>>>>>>> origin/particles
class ImportModel : public Model
{
public:
	ImportModel* create() const;

	ImportModel();
	ImportModel(const ImportModel & tocpy);
	~ImportModel();

	/**
	* @brief Load the model from file.
	*
	* @param filename - The file name.
	*
	* @return bool - If the model loaded.
	*/
	bool loadModel(std::string filename);
<<<<<<< HEAD
	void setScale(vec3 & toset);

	void update();
	void render(const vec3 & transmat);

	std::vector<vec3>& getVerticies();

private:
	void setMinsAndMaxs();
	std::string RandomString(unsigned len);
	std::vector<vec3> Vertices;
	std::vector<vec2> texCoords;
	std::vector<vec3> Normals;
	std::vector<unsigned> vertIndex;
	std::string texture;
	const aiScene *model;

	void setVertices(aiMesh *mesh);
	void setTexCoords(aiMesh *mesh);
	void setNormals(aiMesh *mesh);
	void setIndexes(aiMesh *mesh);
=======

	/**
	* @brief Set the scale vector.
	*
	* @param toset - The scale vector.
	*/
	void setScale(vec3 & toset);

	/**
	* @brief Update function.
	*/
	void update();

	/**
	* @brief rendering function.
	*
	* @param transmat - The translation matrix.
	*/
	void render(const vec3 & transmat);

	/**
	* @brief Get the vertices of the model.
	*
	* @return vector<ve3> - The verticies of the model.
	*/
	std::vector<vec3>& getVerticies();

private:
	/**
	* @brief Set the max and min values.
	*/
	void setMinsAndMaxs();

	/**
	* @brief Create a random string.
	*
	* @param len - The length of the string.
	*
	* @return string - The random string.
	*/
	std::string RandomString(unsigned len);

	/// Vector for the verticies.
	std::vector<vec3> Vertices;
	/// Vector for the texture coords.
	std::vector<vec2> texCoords;
	/// Vector for the normals.
	std::vector<vec3> Normals;
	/// Vector for the indexies
	std::vector<unsigned> vertIndex;
	/// The texture data.
	std::string texture;
	/// The model data.
	const aiScene *model;

	/**
	* @brief Set the vertices.
	*
	* @param mesh - The Mesh.
	*/
	void setVertices(aiMesh *mesh);

	/**
	* @brief Set the texture coords.
	*
	* @param mesh - The Mesh.
	*/
	void setTexCoords(aiMesh *mesh);

	/**
	* @brief Set the normals.
	*
	* @param mesh - The Mesh.
	*/
	void setNormals(aiMesh *mesh);

	/**
	* @brief Set the indexies.
	*
	* @param mesh - The Mesh.
	*/
	void setIndexes(aiMesh *mesh);

	/**
	* @brief Set the center of the point.
	*
	* @param point - The position.
	*/
>>>>>>> origin/particles
	void centerOnPoint(vec3 &point);
};

