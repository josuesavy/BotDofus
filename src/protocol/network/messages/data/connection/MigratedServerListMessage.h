#ifndef MIGRATEDSERVERLISTMESSAGE_H
#define MIGRATEDSERVERLISTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MigratedServerListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MigratedServerListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MigratedServerListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MigratedServerListMessage(FuncTree tree);
  MigratedServerListMessage();

  QList<uint> migratedServerIds;

private:
  void _migratedServerIdstreeFunc(Reader *input);
  void _migratedServerIdsFunc(Reader *input);

  FuncTree _migratedServerIdstree;
};

#endif // MIGRATEDSERVERLISTMESSAGE_H