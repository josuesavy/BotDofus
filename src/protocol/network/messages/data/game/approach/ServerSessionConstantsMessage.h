#ifndef SERVERSESSIONCONSTANTSMESSAGE_H
#define SERVERSESSIONCONSTANTSMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/approach/ServerSessionConstant.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ServerSessionConstantsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerSessionConstantsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerSessionConstantsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerSessionConstantsMessage(FuncTree tree);
  ServerSessionConstantsMessage();

  QList<QSharedPointer<ServerSessionConstant>> variables;

private:
  void _variablestreeFunc(Reader *input);
  void _variablesFunc(Reader *input);

  FuncTree _variablestree;
};

#endif // SERVERSESSIONCONSTANTSMESSAGE_H