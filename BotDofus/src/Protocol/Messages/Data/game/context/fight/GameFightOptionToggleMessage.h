#ifndef GAMEFIGHTOPTIONTOGGLEMESSAGE_H
#define GAMEFIGHTOPTIONTOGGLEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameFightOptionToggleMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightOptionToggleMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightOptionToggleMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightOptionToggleMessage(FuncTree tree);
  GameFightOptionToggleMessage();

  uint option;

private:
  void _optionFunc(Reader *input);
};

#endif // GAMEFIGHTOPTIONTOGGLEMESSAGE_H