#ifndef GAMEACTIONFIGHTCASTREQUESTMESSAGE_H
#define GAMEACTIONFIGHTCASTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameActionFightCastRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightCastRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightCastRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightCastRequestMessage(FuncTree tree);
  GameActionFightCastRequestMessage();

  uint spellId;
  int cellId;

private:
  void _spellIdFunc(Reader *input);
  void _cellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTCASTREQUESTMESSAGE_H