#ifndef TEXTURE_H
#define TEXTURE_H

namespace franny::render {
    class Texture {
    public:
        Texture(const char *imgPath,
                int imageFormat,
                int wrap_s_mode,
                int wrap_t_mode,
                int min_filter_mode,
                int mag_filter_mode);

        unsigned int getId() const;
        int getWidth() const;
        int getHeight() const;

        void use() const;

    private:
        unsigned int ID;
        int width;
        int height;
    };
}

#endif //TEXTURE_H
