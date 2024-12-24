#ifndef GAMECONTEXTCREATEREQUESTMESSAGE_H
#define GAMECONTEXTCREATEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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