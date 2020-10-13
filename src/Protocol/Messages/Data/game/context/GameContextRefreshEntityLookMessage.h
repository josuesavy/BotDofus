#ifndef GAMECONTEXTREFRESHENTITYLOOKMESSAGE_H
#define GAMECONTEXTREFRESHENTITYLOOKMESSAGE_H

#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameContextRefreshEntityLookMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextRefreshEntityLookMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextRefreshEntityLookMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextRefreshEntityLookMessage(FuncTree tree);
  GameContextRefreshEntityLookMessage();

  double id;
  QSharedPointer<EntityLook> look;

private:
  void _idFunc(Reader *input);
  void _looktreeFunc(Reader *input);

  FuncTree _looktree;
};

#endif // GAMECONTEXTREFRESHENTITYLOOKMESSAGE_H