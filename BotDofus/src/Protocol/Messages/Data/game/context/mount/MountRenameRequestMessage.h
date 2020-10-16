#ifndef MOUNTRENAMEREQUESTMESSAGE_H
#define MOUNTRENAMEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class MountRenameRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountRenameRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountRenameRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountRenameRequestMessage(FuncTree tree);
  MountRenameRequestMessage();

  QString name;
  int mountId;

private:
  void _nameFunc(Reader *input);
  void _mountIdFunc(Reader *input);
};

#endif // MOUNTRENAMEREQUESTMESSAGE_H