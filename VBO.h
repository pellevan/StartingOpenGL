#ifndef VBO_CLASS_HEADER
#define VBO_CLASS_HEADER

#include <glad/glad.h>

class VBO
{
	public:
		GLuint ID;									// Reference ID to the VBO
		VBO(GLfloat* vertices, GLsizeiptr size);	// Constructor that creates VBO and links it to vertices

		void Bind();								// Binds VBO
		void Unbind();								// Unbinds VBO
		void Delete();								// Deletes the VBO
};

#endif