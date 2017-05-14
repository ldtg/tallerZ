#include "ObjectMap.h"

ObjectMap::ObjectMap(const char *type) {
    this->type = type;
}

std::string ObjectMap::getType() const {
    return this->type;
}
