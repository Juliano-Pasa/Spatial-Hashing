#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include "glad.h"
#include <GLFW/glfw3.h>
#include <vector>

#include "curva.hpp"
#include "glslprogram.hpp"

namespace spatialhash
{
	class Plane
	{
	public:
		Plane(GLFWwindow* window, int size = 1);

		void Initialize();
		void Update(double t);
		void Render();

	private:
		void genCurve();
		void genCircles();
		void genCirclesBuffers();
		void genCurveBuffers();
		void CheckAllCollisions();
		void CheckHashCollisions();
		void UpdateViewMatrix();
		void PaintCollidedCircle(int centerIndex);
		void PrintParameters();
		bool CollidesWithCurve(vec3 centerPos, vec3 point1, vec3 point2);

		void processInput(double deltaTime);
		void UpdateLOD(int factor);
		void CheckLODChange();

		// Hash
		void GenerateHashTable();
		int HashFunction(vec3 point);
		int hashDimension;
		float hashSize;
		std::vector<glm::ivec3> hashPivots;
		std::vector<int> hashTable;

		GLuint vaoIDs[2];
		std::vector<vec3> normals;

		std::vector<vec3> circlesVertices;
		std::vector<vec3> circlesColors;
		std::vector<unsigned int> circlesIndices;

		std::vector<vec3> curveVertices;
		std::vector<vec3> curveColors;
		std::vector<unsigned int> curveIndices;

		GLSLProgram shader;
		GLFWwindow* window;

		glm::mat4 modelMatrix;
		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
		glm::mat4 modelViewProjectionMatrix;
		glm::mat4 modelViewMatrix;

		vec3 planePos;
		vec3 camPos;

		float camSpeed;
		float size;
		float curveSteps;
		float maxCoords;

		int circleSteps;
		int numCircles;
		int numControlPoints;
		int LODFactor;
		GLuint primitiveRestartIndex;

		bool wireframe;
	};
}

#endif // __PLANE_HPP__