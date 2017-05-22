#ifndef TALLERZ_HANDLERFACTORY_H
#define TALLERZ_HANDLERFACTORY_H

#include "Handler.h"
class HandlerFactory {
 public:
  static Handler* get(unsigned int type);
};

#endif //TALLERZ_HANDLERFACTORY_H
