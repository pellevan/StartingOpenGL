#ifndef VAO_CLASS_HEADER
#define VAO_CLASS_HEADER

#include <glad/glad.h>
#include "VBO.h"

class VAO
{
	public:
		GLuint ID;									// ID reference for VAO
		VAO();										// Constructor that generates an ID

		void LinkVBO(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset); // Links a VBO to the VAO using a certain layout
		void Bind();								// Binds the VAO
		void Unbind();								// Unbinds the VAO
		void Delete();								// Deletes the VAO
};

#endif	