#ifndef IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE_H
#define IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE_H

#include "src/Protocol/Types/Data/version/Version.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/connection/IdentificationFailedMessage.h"

class IdentificationFailedForBadVersionMessage : public IdentificationFailedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdentificationFailedForBadVersionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdentificationFailedForBadVersionMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdentificationFailedForBadVersionMessage(FuncTree tree);
  IdentificationFailedForBadVersionMessage();

  Version requiredVersion;

private:
  void _requiredVersiontreeFunc(Reader *input);

  FuncTree _requiredVersiontree;
};

#endif // IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE_H