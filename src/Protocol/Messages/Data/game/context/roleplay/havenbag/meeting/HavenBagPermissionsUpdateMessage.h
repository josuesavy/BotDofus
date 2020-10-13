#ifndef HAVENBAGPERMISSIONSUPDATEMESSAGE_H
#define HAVENBAGPERMISSIONSUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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