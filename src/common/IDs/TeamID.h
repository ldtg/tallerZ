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
  template<class Archive>
  void serialize(Archive &archive){
    archive(id);
  }
};

#endif //TALLERZ_TEAMID_H
