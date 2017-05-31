//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_CLICK_H
#define TALLERZ_CLICK_H

#include <SDL2/SDL_events.h>
#include "Events/Event.h"

/*
 * En el zod_engine es así:
 * - Un boton se ejecuta al levantar el boton del mouse, osea usando: SDL_MOUSEBUTTONUP
 * - Un boton hace solo la animacion de "presion" si se apreta el boton: SDL_MOUSEBUTTONDOWN
 * - Parece ser que hay una relacion directa entre Seleccionar un area (seleccionando las
 * unidades adentro de ese area) y hacer un click sobre una unidad: cuando haces click sobre
 * una unidad que esta rodeada de varias unidades nunca se selecciona esa unica unidad sino
 * que se selecciona junto todas esas unidades que estan alrededor, es como que hace el mismo
 * efecto de seleccionar un area pero con un area minima.
 */

/**
 *  \brief Mouse button event structure (event.button.*)

typedef struct SDL_MouseButtonEvent
{
  Uint32 type;        *//**< ::SDL_MOUSEBUTTONDOWN or ::SDL_MOUSEBUTTONUP *//*
  Uint32 timestamp;
  Uint32 windowID;    *//**< The window with mouse focus, if any *//*
  Uint32 which;       *//**< The mouse instance id, or SDL_TOUCH_MOUSEID *//*
  Uint8 button;       *//**< The mouse button index *//*
  Uint8 state;        *//**< ::SDL_PRESSED or ::SDL_RELEASED *//*
  Uint8 clicks;       *//**< 1 for single-click, 2 for double-click, etc. *//*
  Uint8 padding1;
  Sint32 x;           *//**< X coordinate, relative to window *//*
  Sint32 y;           *//**< Y coordinate, relative to window *//*
} SDL_MouseButtonEvent;*/

class LeftClickEvent : public Event {
/*
 private:
  SDL_MouseButtonEvent event;
 public:
  Click(SDL_MouseButtonEvent& event) : event(event) {}
  ~Click(){}

  SDL_MouseButtonEvent get_click_data();
*/
 private:
  int x;
  int y;
 public:
  LeftClickEvent(int x, int y);
  void process();
 };

#endif //TALLERZ_CLICK_H
