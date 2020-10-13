#ifndef GUILDHOUSEREMOVEMESSAGE_H
#define GUILDHOUSEREMOVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildHouseRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildHouseRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildHouseRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildHouseRemoveMessage(FuncTree tree);
  GuildHouseRemoveMessage();

  uint houseId;
  uint instanceId;
  bool secondHand;

private:
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _secondHandFunc(Reader *input);
};

#endif // GUILDHOUSEREMOVEMESSAGE_H