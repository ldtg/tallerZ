#ifndef TALLERZ_SERVERTODESTROYEDEVENT_H
#define TALLERZ_SERVERTODESTROYEDEVENT_H

#include <common/DataEvents/TerrainObject/dataTerrainObjectIDEvent.h>
#include <server/model/Events/serverEvent.h>

class serverTODestroyedEvent : public serverEvent {
private:
  dataTerrainObjectIDEvent data;

 public:
  serverTODestroyedEvent(const TerrainObjectID &id);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERTODESTROYEDEVENT_H
