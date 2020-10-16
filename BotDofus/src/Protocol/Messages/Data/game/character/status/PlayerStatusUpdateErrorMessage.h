#ifndef PLAYERSTATUSUPDATEERRORMESSAGE_H
#define PLAYERSTATUSUPDATEERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PlayerStatusUpdateErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PlayerStatusUpdateErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PlayerStatusUpdateErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PlayerStatusUpdateErrorMessage(FuncTree tree);
  PlayerStatusUpdateErrorMessage();
};

#endif // PLAYERSTATUSUPDATEERRORMESSAGE_H