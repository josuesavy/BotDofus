#ifndef PRISMSETTINGSREQUESTMESSAGE_H
#define PRISMSETTINGSREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PrismSettingsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismSettingsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismSettingsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismSettingsRequestMessage(FuncTree tree);
  PrismSettingsRequestMessage();

  uint subAreaId;
  uint startDefenseTime;

private:
  void _subAreaIdFunc(Reader *input);
  void _startDefenseTimeFunc(Reader *input);
};

#endif // PRISMSETTINGSREQUESTMESSAGE_H