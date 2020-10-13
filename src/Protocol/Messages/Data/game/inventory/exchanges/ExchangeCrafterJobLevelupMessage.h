#ifndef EXCHANGECRAFTERJOBLEVELUPMESSAGE_H
#define EXCHANGECRAFTERJOBLEVELUPMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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