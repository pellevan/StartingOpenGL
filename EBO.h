#ifndef EBO_CLASS_HEADER
#define EBO_CLASS_HEADER

#include <glad/glad.h>

class EBO
{
	public:
		GLuint ID;									// ID reference of EBO
		EBO(GLuint* indices, GLsizeiptr size);		// Constructor that generates EBO and links it to indices

		void Bind();								// Binds the EBO
		void Unbind();								// Unbinds the EBO
		void Delete();								// Delete the EBO
};

#endif