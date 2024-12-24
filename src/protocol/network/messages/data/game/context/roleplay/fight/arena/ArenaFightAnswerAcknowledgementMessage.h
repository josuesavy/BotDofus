#ifndef ARENAFIGHTANSWERACKNOWLEDGEMENTMESSAGE_H
#define ARENAFIGHTANSWERACKNOWLEDGEMENTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ArenaFightAnswerAcknowledgementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ArenaFightAnswerAcknowledgementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ArenaFightAnswerAcknowledgementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ArenaFightAnswerAcknowledgementMessage(FuncTree tree);
  ArenaFightAnswerAcknowledgementMessage();

  bool acknowledged;

private:
  void _acknowledgedFunc(Reader *input);
};

#endif // ARENAFIGHTANSWERACKNOWLEDGEMENTMESSAGE_H