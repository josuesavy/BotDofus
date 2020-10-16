#ifndef GAMEFIGHTSTARTMESSAGE_H
#define GAMEFIGHTSTARTMESSAGE_H

#include "src/Protocol/Types/Data/game/idol/Idol.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightStartMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightStartMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightStartMessage(FuncTree tree);
  GameFightStartMessage();

  QList<QSharedPointer<Idol>> idols;

private:
  void _idolstreeFunc(Reader *input);
  void _idolsFunc(Reader *input);

  FuncTree _idolstree;
};

#endif // GAMEFIGHTSTARTMESSAGE_H