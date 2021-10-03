#ifndef PRISMSETTINGSERRORMESSAGE_H
#define PRISMSETTINGSERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismSettingsErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismSettingsErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismSettingsErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismSettingsErrorMessage(FuncTree tree);
  PrismSettingsErrorMessage();
};

#endif // PRISMSETTINGSERRORMESSAGE_H