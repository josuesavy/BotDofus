#ifndef IDENTIFICATIONFAILEDBANNEDMESSAGE_H
#define IDENTIFICATIONFAILEDBANNEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/connection/IdentificationFailedMessage.h"

class IdentificationFailedBannedMessage : public IdentificationFailedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdentificationFailedBannedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdentificationFailedBannedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdentificationFailedBannedMessage(FuncTree tree);
  IdentificationFailedBannedMessage();

  double banEndDate;

private:
  void _banEndDateFunc(Reader *input);
};

#endif // IDENTIFICATIONFAILEDBANNEDMESSAGE_H