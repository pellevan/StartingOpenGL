#include "Texture.h"

Texture::Texture(const char* image, const GLenum tex_type, const GLenum slot, const GLenum format, const GLenum pixel_type)
	:	type(tex_type),
		slot(slot)
{
	int width_img, height_img, nr_channels;
	stbi_set_flip_vertically_on_load(true);

	// Reads the image from a file and stores it in bytes
	unsigned char* bytes = stbi_load(image, &width_img, &height_img, &nr_channels, 0);

	// Generates an OpenGL texture object
	glGenTextures(1, &id);

	// Assigns the texture to a Texture unit
	glActiveTexture(slot);
	glBindTexture(tex_type, id);

	// Configures the algorithm used to make images smaller or bigger
	glTexParameteri(tex_type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(tex_type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Configure the way the texture repeats 
	glTexParameteri(tex_type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(tex_type, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Assigns the image to the OpenGL Texture object
	glTexImage2D(tex_type, 0, GL_RGB, width_img, height_img, 0, format, pixel_type, bytes);

	// Generate MipMaps
	glGenerateMipmap(tex_type);

	// Deletes the image data as it is already in the OpenGL Texture object
	stbi_image_free(bytes);

	// Unbinds the OpenGL Texture object to that it can't be modified
	glBindTexture(tex_type, 0);
}

void Texture::tex_unit(Shader& shader, const char* uniform, const GLuint unit)
{
	const GLuint tex_uni = glGetUniformLocation(shader.ID, uniform);

	shader.Activate();
	glUniform1i(tex_uni, unit);
}

void Texture::Bind() const
{
	glActiveTexture(slot);
	glBindTexture(type, id);
}

void Texture::Unbind() const
{
	glBindTexture(type, 0);
}

void Texture::Delete() const
{
	glDeleteTextures(1, &id);
}