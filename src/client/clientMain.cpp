
#include <common/Socket/Socket.h>
#include <common/Map/Map.h>
#include <common/DataClientServerMessages/dataServerClientAccepted.h>
#include <client/view/Camera.h>
#include <client/model/Events/EventHandler.h>
#include <client/controller/Controller.h>
#include <cereal/archives/binary.hpp>
#include <common/DataClientServerMessages/dataClientConnectedMessage.h>
#include <clientCommandSender.h>
#include <clientEventReceiver.h>
void sendPlayerConnected(Socket &socket,
                         unsigned short team,
                         const std::string &map);
dataServerClientAccepted getDataClientAccepted(Socket &socket);
Map getMap(Socket &socket);
int main(int argc, char *argv[]) {
  Socket socket;
  socket.connectToServer(argv[1], argv[2]);

  sendPlayerConnected(socket, std::stoi(argv[3]), argv[4]);
  dataServerClientAccepted accepted = getDataClientAccepted(socket);

  Map map = getMap(socket);

  Queue<Event *> eventQueue;
  Queue<clientCommand *> commandsQueue;
  clientCommandSender commandSender(socket, commandsQueue);
  commandSender.start();
  clientEventReceiver eventReceiver(socket, eventQueue);
  eventReceiver.start();
  GameControllerProxy gcp(commandsQueue);

  Camera camera(WINDOWWIDTH, WINDOWHEIGHT);
  EventHandler eventHandler;

  View view(map, eventHandler, camera, accepted.id.getColor());
  Model model(map, gcp, camera, view, accepted.id, accepted.teamID);

  eventHandler.setView(&view);
  eventHandler.setModel(&model);

  SDL_Event e;

  Controller controller(eventHandler);

  //While application is running
  while (!view.quit()) {
    while (SDL_PollEvent(&e) != 0) {
      controller.handle(&e);
    }
    // Chequeo pos del mouse para saber
    // si se debe mover camara.
    controller.checkMouseState(&e);
    while (!eventQueue.empty())
      eventHandler.add(eventQueue.pop());
    view.update();
  }
  commandsQueue.push(nullptr);
  commandSender.stop();
  eventReceiver.stop();
  commandSender.join();
  eventReceiver.join();
  return 0;
}
Map getMap(Socket &socket) {
  std::stringstream mapin(socket.rcv_str_preconcatenated());
  Map map;
  cereal::BinaryInputArchive iarchive(mapin);
  iarchive(map);
  return map;
}
dataServerClientAccepted getDataClientAccepted(Socket &socket) {
  dataServerClientAccepted accepted;
  std::stringstream datain(socket.rcv_str_preconcatenated());
  cereal::BinaryInputArchive iarchive(datain);
  iarchive(accepted);
  return accepted;
}
void sendPlayerConnected(Socket &socket,
                         unsigned short team,
                         const std::string &map) {
  dataClientConnectedMessage data;
  data.team = team;
  data.map = map;

  std::stringstream dataout;
  cereal::BinaryOutputArchive oarchive(dataout);
  oarchive(data);
  socket.send_str_preconcatenated(dataout.str());
}
