#include "Button.h"

/**
 * Constructor
 * @param window : ventana sobre la que se realiza el click (generalmente: Main_Window)
 */
Button::Button(Window *window) {
  this->window = window;
}

/**
 * Destructor: se eliminan las texturas cargadas.
 */
Button::~Button() {
  if (button_up != NULL) {
    delete this->button_up;
  }
  if (button_down != NULL) {
    delete this->button_down;
  }
}


/**
 * load_texture_up: Opcional
 * @param path : ruta de archivo de la imagen de boton levantada
 */
void Button::load_texture_up(const std::string &path) {
  try {
    this->button_up = new Texture(path, window);
    this->button_up->renderize(window, &renderQuad);
  } catch (const std::exception &e) {
    throw Front_end_exception("Button::load_texture_up: %s\n", e.what());
  }
}

/**
 * load_texture_down: Opcional
 * @param path : ruta de archivo de la imagen de boton apretada
 */
void Button::load_texture_down(const std::string &path) {
  try {
    this->button_down = new Texture(path, window);
  } catch (const std::exception &e) {
    throw Front_end_exception("Button::load_texture_down: %s\n", e.what());
  }
}

/**
 * handle_event:
 * invoca al método que cambia el estado gráfico del boton que
 * a su vez, si el evento es un mouse_button_up llama a
 * button_launch que dispara la lógica asociada al botón
 */
void Button::handle_click() {
  this->on_button_pressed();

}

/**
 * on_button_pressed
 * Lo unico que se realiza al apretar un boton es renderizar la textura
 * de boton apretado.
 */
void Button::on_button_pressed() {
  if (this->button_down != NULL) {
    this->button_down->renderize(this->window, &this->renderQuad);
    this->button_launch();
  }
}

/**
 * inRectangle
 * @param x : coordenada x
 * @param y : coordenada y
 * @return : Si las coordenadas indicadas se ubican sobre el botón.
 */
bool Button::inRectangle(int x, int y) {
  return (x > renderQuad.x
      && x < (renderQuad.x + renderQuad.w)
      && y > renderQuad.y
      && y < (renderQuad.y + renderQuad.h));
}

void Button::draw(SDL_Renderer *render, Camera &camera) {
  SDL_RenderCopy(render, button_up->get_texture(), NULL, &renderQuad);
}
