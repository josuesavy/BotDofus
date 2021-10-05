#ifndef UPDATESELFAGRESSABLESTATUSMESSAGE_H
#define UPDATESELFAGRESSABLESTATUSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class UpdateSelfAgressableStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateSelfAgressableStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateSelfAgressableStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateSelfAgressableStatusMessage(FuncTree tree);
  UpdateSelfAgressableStatusMessage();

  uint status;
  uint probationTime;

private:
  void _statusFunc(Reader *input);
  void _probationTimeFunc(Reader *input);
};

#endif // UPDATESELFAGRESSABLESTATUSMESSAGE_H