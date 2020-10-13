#ifndef PRISMSETTINGSERRORMESSAGE_H
#define PRISMSETTINGSERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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