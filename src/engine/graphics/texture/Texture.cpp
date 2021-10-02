//
// Created by Luc Drenth on 02/10/2021.
//

#include "Texture.h"
#include "engine/logger/GLErrorHandler.h"
#include "engine/vendor/stb_image.h"

#include <GL/glew.h>

Texture::Texture()
{
}

Texture::~Texture()
{
    GLCall(glDeleteTextures(1, &rendererId_));
}

void Texture::bind(unsigned int slot) const
{
    if (hasError_)
    {
        return;
    }

    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    GLCall(glBindTexture(GL_TEXTURE_2D, rendererId_));
}

void Texture::unbind()
{
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

void Texture::init(const std::string& filePath)
{
    filePath_ = filePath;
    stbi_set_flip_vertically_on_load(true);
    localBuffer_ = stbi_load(filePath_.c_str(), &width_, &height_, &bitsPerPixel_, 4);

    if (!localBuffer_)
    {
        std::cout << "ERROR: texture not found with path '" << filePath << "'" << std::endl;
        hasError_ = true;
        return;
    }

    GLCall(glGenTextures(1, &rendererId_));
    GLCall(glBindTexture(GL_TEXTURE_2D, rendererId_));

    GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR) );
    GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR) );
    GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE) );
    GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) );

    GLCall( glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer_) );
    unbind();

    stbi_image_free(localBuffer_);
}

