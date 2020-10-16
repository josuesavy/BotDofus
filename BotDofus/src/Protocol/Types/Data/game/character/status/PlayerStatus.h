#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PlayerStatus : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PlayerStatus(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PlayerStatus(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PlayerStatus(FuncTree tree);
  PlayerStatus();
  bool operator==(const PlayerStatus &compared);

  uint statusId;

private:
  void _statusIdFunc(Reader *input);
};

#endif // PLAYERSTATUS_H