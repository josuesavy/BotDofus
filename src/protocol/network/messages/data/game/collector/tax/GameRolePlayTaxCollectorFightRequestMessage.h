#ifndef GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE_H
#define GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayTaxCollectorFightRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayTaxCollectorFightRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayTaxCollectorFightRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayTaxCollectorFightRequestMessage(FuncTree tree);
  GameRolePlayTaxCollectorFightRequestMessage();
};

#endif // GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE_H