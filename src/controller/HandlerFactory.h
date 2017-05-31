#ifndef TALLERZ_HANDLERFACTORY_H
#define TALLERZ_HANDLERFACTORY_H

#include "Handler.h"
class HandlerFactory {
 private:

 public:
  static Handler* get(SDL_Event *e);
};

#endif //TALLERZ_HANDLERFACTORY_H
