#ifndef GAMECONTEXTCREATEREQUESTMESSAGE_H
#define GAMECONTEXTCREATEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameContextCreateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextCreateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextCreateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextCreateRequestMessage(FuncTree tree);
  GameContextCreateRequestMessage();
};

#endif // GAMECONTEXTCREATEREQUESTMESSAGE_H