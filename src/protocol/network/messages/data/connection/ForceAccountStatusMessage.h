#ifndef FORCEACCOUNTSTATUSMESSAGE_H
#define FORCEACCOUNTSTATUSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ForceAccountStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForceAccountStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForceAccountStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForceAccountStatusMessage(FuncTree tree);
  ForceAccountStatusMessage();

  bool force;
  uint forcedAccountId;
  QString forcedNickname;
  QString forcedTag;

private:
  void _forceFunc(Reader *input);
  void _forcedAccountIdFunc(Reader *input);
  void _forcedNicknameFunc(Reader *input);
  void _forcedTagFunc(Reader *input);
};

#endif // FORCEACCOUNTSTATUSMESSAGE_H