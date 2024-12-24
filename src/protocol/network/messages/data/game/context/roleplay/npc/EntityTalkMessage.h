#ifndef ENTITYTALKMESSAGE_H
#define ENTITYTALKMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class EntityTalkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EntityTalkMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EntityTalkMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EntityTalkMessage(FuncTree tree);
  EntityTalkMessage();

  double entityId;
  uint textId;
  QList<QString> parameters;

private:
  void _entityIdFunc(Reader *input);
  void _textIdFunc(Reader *input);
  void _parameterstreeFunc(Reader *input);
  void _parametersFunc(Reader *input);

  FuncTree _parameterstree;
};

#endif // ENTITYTALKMESSAGE_H