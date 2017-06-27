#include <common/Socket/Socket.h>
#include <common/Map/Map.h>
#include <common/DataClientServerMessages/dataServerClientAccepted.h>
#include <client/view/Camera.h>
#include <client/model/Events/EventHandler.h>
#include <client/controller/Controller.h>
#include <cereal/archives/binary.hpp>
#include <common/DataClientServerMessages/dataClientConnectedMessage.h>
#include <client/lobby/clientLobby.h>
#include <ClientEventReceiver.h>
#include "ClientCommandSender.h"
void sendPlayerConnected(Socket &socket,
                         unsigned short team,
                         const std::string &map);

dataServerClientAccepted getDataClientAccepted(Socket &socket);

Map getMap(Socket &socket);

Login_Details display_login_settings(int argc, char *argv[]) {
  try {
    Gtk::Main kit(argc, argv);
    clientLobby lobby;
    lobby.get_window()->show_all();
    Gtk::Main::run(*lobby.get_window());
    return lobby.get_login_details();
  } catch (const std::exception &e) {
    throw Close_Exception("Program Close");
  }
}
//retorna true si el server esta online, recibe el eventReceiver porque es el primero que se da cuenta cuando se desconecta el server
bool serverConnected(const ClientEventReceiver &receiver);

int main(int argc, char *argv[]) {
  Socket socket;
  Login_Details ld;

  try {
    ld = display_login_settings(argc, argv);
  } catch (const Close_Exception &e) {
    return 0;
  }

  try {
    socket.connectToServer(ld.ip, ld.port);
  } catch (const SocketException &e) {
    std::cerr << "No se pudo conectar al servidor" << std::endl;
    return 0;
  }

  try {
    sendPlayerConnected(socket, (unsigned short) std::stoi(ld.team), ld.map);
    dataServerClientAccepted accepted = getDataClientAccepted(socket);

    Map map = getMap(socket);

    Queue<Event *> eventQueue;
    Queue<ClientCommand *> commandsQueue;
    ClientCommandSender commandSender(socket, commandsQueue);
    commandSender.start();
    ClientEventReceiver eventReceiver(socket, eventQueue);
    eventReceiver.start();
    GameControllerProxy gcp(commandsQueue);
    Camera camera(WINDOWWIDHT,
                  WINDOWHEIGHT,
                  map.getWidht(),
                  map.getHeight(),
                  map.getFortPos(accepted.id));
    EventHandler eventHandler;

    View view(map, eventHandler, camera, accepted.id.getColor());
    Model model(map, gcp, camera, view, accepted.id, accepted.teamID);

    eventHandler.setView(&view);
    eventHandler.setModel(&model);

    SDL_Event e;

    Controller controller(eventHandler);

    //While application is running
    while (!view.quit() && serverConnected(eventReceiver)) {
      while (SDL_PollEvent(&e) != 0) {
        controller.handle(&e);
      }
      // Chequeo pos del mouse para saber
      // si se debe mover camara.
      controller.checkMouseState(&e);
      while (!eventQueue.empty()) {
        eventHandler.add(eventQueue.pop());
      }
      view.tick();
    }
    commandsQueue.push(nullptr);
    commandSender.stop();
    eventReceiver.stop();
    commandSender.join();
    eventReceiver.join();
  } catch (const SocketException &e) {
    std::cerr << "Servidor desconectado" << std::endl;

    return 0;
  }
  return 0;
}
bool serverConnected(const ClientEventReceiver &receiver) {
  if (!receiver.isOpen()) {
    std::cerr << "Servidor desconectado" << std::endl;
    return false;
  }
  return true;
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
