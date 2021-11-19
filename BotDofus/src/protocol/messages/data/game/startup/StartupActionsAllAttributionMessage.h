#ifndef STARTUPACTIONSALLATTRIBUTIONMESSAGE_H
#define STARTUPACTIONSALLATTRIBUTIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartupActionsAllAttributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartupActionsAllAttributionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartupActionsAllAttributionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartupActionsAllAttributionMessage(FuncTree tree);
  StartupActionsAllAttributionMessage();

  double characterId;

private:
  void _characterIdFunc(Reader *input);
};

#endif // STARTUPACTIONSALLATTRIBUTIONMESSAGE_H