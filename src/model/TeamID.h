#ifndef TALLERZ_TEAMID_H
#define TALLERZ_TEAMID_H

class TeamID {
  static unsigned short nextID;
 private:
  unsigned short id;
 public:
  TeamID();
  bool operator<(const TeamID &other) const;
  bool operator==(const TeamID &other) const;
  bool operator!=(const TeamID &other) const;
};

#endif //TALLERZ_TEAMID_H
