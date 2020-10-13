#ifndef GAMECONTEXTCREATEMESSAGE_H
#define GAMECONTEXTCREATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameContextCreateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextCreateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextCreateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextCreateMessage(FuncTree tree);
  GameContextCreateMessage();

  uint context;

private:
  void _contextFunc(Reader *input);
};

#endif // GAMECONTEXTCREATEMESSAGE_H