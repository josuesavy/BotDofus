#ifndef HAVENBAGPERMISSIONSUPDATEMESSAGE_H
#define HAVENBAGPERMISSIONSUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HavenBagPermissionsUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagPermissionsUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagPermissionsUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagPermissionsUpdateMessage(FuncTree tree);
  HavenBagPermissionsUpdateMessage();

  uint permissions;

private:
  void _permissionsFunc(Reader *input);
};

#endif // HAVENBAGPERMISSIONSUPDATEMESSAGE_H