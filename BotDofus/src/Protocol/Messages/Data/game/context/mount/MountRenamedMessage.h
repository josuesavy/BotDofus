#ifndef MOUNTRENAMEDMESSAGE_H
#define MOUNTRENAMEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountRenamedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountRenamedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountRenamedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountRenamedMessage(FuncTree tree);
  MountRenamedMessage();

  int mountId;
  QString name;

private:
  void _mountIdFunc(Reader *input);
  void _nameFunc(Reader *input);
};

#endif // MOUNTRENAMEDMESSAGE_H