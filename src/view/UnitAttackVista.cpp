#include "UnitAttackVista.h"
#include "Image.h"

UnitAttackVista::UnitAttackVista(const char *file, int num_frames, int speed)
    : Sprite(file, num_frames, speed) {}

void UnitAttackVista::draw(SDL_Renderer *render) {
//  int cur_frame_aux = cur_frame/(speed*num_frames);
  int cur_frame_aux = cur_frame/speed;

  std::string file_image = filename + std::to_string(cur_frame_aux)
      + std::string(".png");

  Image image(file_image.c_str());
  image.setPos(Position(x, y));
  width = image.getWidth();
  height = image.getHeight();
  image.set_texture(render);

  image.draw(render);

  ++cur_frame;
  //Cycle animation
//  if (cur_frame/(speed*num_frames) >= num_frames) {
  if (cur_frame/speed >= num_frames) {
    cur_frame = (num_frames-2)*speed;
    _doCycle = true;
  }
}
