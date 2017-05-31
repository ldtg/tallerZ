#include "TerrainObjectState.h"
TerrainObjectState::TerrainObjectState(const Position &position,
                                       unsigned short size,
                                       unsigned short health, bool passable)
    : centerPosition(
    position), size(size), health(health), passable(passable) {

}
