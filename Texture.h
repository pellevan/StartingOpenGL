#ifndef TEXTURE_CLASS_HEADER
#define TEXTURE_CLASS_HEADER

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "shaderClass.h"

class Texture
{
	public:
		GLuint id;
		GLenum type;
		GLenum slot;
		Texture(const char* image, GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type);

		void tex_unit(Shader& shader, const char* uniform, GLuint unit);
		void Bind() const;
		void Unbind() const;
		void Delete() const;
};

#endif
