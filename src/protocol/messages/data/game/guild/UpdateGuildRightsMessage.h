#ifndef UPDATEGUILDRIGHTSMESSAGE_H
#define UPDATEGUILDRIGHTSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class UpdateGuildRightsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateGuildRightsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateGuildRightsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateGuildRightsMessage(FuncTree tree);
  UpdateGuildRightsMessage();

  uint rankId;
  QList<uint> rights;

private:
  void _rankIdFunc(Reader *input);
  void _rightstreeFunc(Reader *input);
  void _rightsFunc(Reader *input);

  FuncTree _rightstree;
};

#endif // UPDATEGUILDRIGHTSMESSAGE_H