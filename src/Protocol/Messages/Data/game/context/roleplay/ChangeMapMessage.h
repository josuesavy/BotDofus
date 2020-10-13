#ifndef CHANGEMAPMESSAGE_H
#define CHANGEMAPMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ChangeMapMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChangeMapMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChangeMapMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChangeMapMessage(FuncTree tree);
  ChangeMapMessage();

  double mapId;
  bool autopilot;

private:
  void _mapIdFunc(Reader *input);
  void _autopilotFunc(Reader *input);
};

#endif // CHANGEMAPMESSAGE_H