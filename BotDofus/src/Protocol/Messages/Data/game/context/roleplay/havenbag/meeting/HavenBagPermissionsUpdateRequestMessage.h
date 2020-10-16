#ifndef HAVENBAGPERMISSIONSUPDATEREQUESTMESSAGE_H
#define HAVENBAGPERMISSIONSUPDATEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HavenBagPermissionsUpdateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagPermissionsUpdateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagPermissionsUpdateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagPermissionsUpdateRequestMessage(FuncTree tree);
  HavenBagPermissionsUpdateRequestMessage();

  uint permissions;

private:
  void _permissionsFunc(Reader *input);
};

#endif // HAVENBAGPERMISSIONSUPDATEREQUESTMESSAGE_H