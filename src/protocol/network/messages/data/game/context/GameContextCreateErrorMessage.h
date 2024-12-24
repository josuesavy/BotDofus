#ifndef GAMECONTEXTCREATEERRORMESSAGE_H
#define GAMECONTEXTCREATEERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameContextCreateErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextCreateErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextCreateErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextCreateErrorMessage(FuncTree tree);
  GameContextCreateErrorMessage();
};

#endif // GAMECONTEXTCREATEERRORMESSAGE_H