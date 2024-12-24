#ifndef EXCHANGECRAFTERJOBLEVELUPMESSAGE_H
#define EXCHANGECRAFTERJOBLEVELUPMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeCrafterJobLevelupMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCrafterJobLevelupMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCrafterJobLevelupMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCrafterJobLevelupMessage(FuncTree tree);
  ExchangeCrafterJobLevelupMessage();

  uint crafterJobLevel;

private:
  void _crafterJobLevelFunc(Reader *input);
};

#endif // EXCHANGECRAFTERJOBLEVELUPMESSAGE_H