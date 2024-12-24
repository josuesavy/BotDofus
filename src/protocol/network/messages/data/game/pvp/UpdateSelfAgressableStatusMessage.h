#ifndef UPDATESELFAGRESSABLESTATUSMESSAGE_H
#define UPDATESELFAGRESSABLESTATUSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
  double probationTime;
  int roleAvAId;
  int pictoScore;

private:
  void _statusFunc(Reader *input);
  void _probationTimeFunc(Reader *input);
  void _roleAvAIdFunc(Reader *input);
  void _pictoScoreFunc(Reader *input);
};

#endif // UPDATESELFAGRESSABLESTATUSMESSAGE_H