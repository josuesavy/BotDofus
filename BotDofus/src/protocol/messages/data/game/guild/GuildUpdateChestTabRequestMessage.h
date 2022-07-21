#ifndef GUILDUPDATECHESTTABREQUESTMESSAGE_H
#define GUILDUPDATECHESTTABREQUESTMESSAGE_H

#include "src/protocol/types/data/game/inventory/UpdatedStorageTabInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildUpdateChestTabRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildUpdateChestTabRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildUpdateChestTabRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildUpdateChestTabRequestMessage(FuncTree tree);
  GuildUpdateChestTabRequestMessage();

  UpdatedStorageTabInformation tab;

private:
  void _tabtreeFunc(Reader *input);

  FuncTree _tabtree;
};

#endif // GUILDUPDATECHESTTABREQUESTMESSAGE_H