#include "franny/render/texture.h";

#include <iostream>
#include <glad/glad.h>
#include <stb/stb_image.h>

using namespace std;

namespace franny::render {
    Texture::Texture(const char *imgPath,
                     const int imageFormat,
                     const int wrap_s_mode,
                     const int wrap_t_mode,
                     const int min_filter_mode,
                     const int mag_filter_mode) {
        ID = 0;
        width = 0;
        height = 0;

        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s_mode);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t_mode);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter_mode);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter_mode);

        stbi_set_flip_vertically_on_load(true);

        int nrChannels;
        unsigned char *data = stbi_load(imgPath, &width, &height, &nrChannels, 0);

        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            cout << "Failed to load texture" << endl;
        }

        stbi_image_free(data);
    }

    void Texture::use() const {
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    unsigned int Texture::getId() const {
        return ID;
    }

    int Texture::getWidth() const {
        return width;
    }

    int Texture::getHeight() const {
        return height;
    }

}
