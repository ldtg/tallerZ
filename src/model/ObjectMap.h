#ifndef TALLERZ_OBJETOMAPA_H
#define TALLERZ_OBJETOMAPA_H

#include <string>

class ObjectMap {
    private:
        std::string type;
    public:
        explicit ObjectMap(const char *type);
        std::string getType() const;

};

#endif //TALLERZ_OBJETOMAPA_H
