#ifndef RELOGINTOKENSTATUSMESSAGE_H
#define RELOGINTOKENSTATUSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ReloginTokenStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ReloginTokenStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ReloginTokenStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ReloginTokenStatusMessage(FuncTree tree);
  ReloginTokenStatusMessage();

  bool validToken;
  QString token;

private:
  void _validTokenFunc(Reader *input);
  void _tokenFunc(Reader *input);
};

#endif // RELOGINTOKENSTATUSMESSAGE_H